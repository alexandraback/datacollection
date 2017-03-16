from itertools import chain, combinations
import math

def powerset(iterable):
  xs = list(iterable)
  # note we return an iterator rather than a list
  return chain.from_iterable( combinations(xs,n) for n in range(len(xs)+1) )

def check(V,d):
	if 2**len(d) < V:
		return False
	possiblesums = []
	for x in list(powerset(d)):
		possiblesums.append(sum(x))
	for v in range(1,V+1):
		if not v in possiblesums:
			return False
	return True

def solve(C,D,V,denoms):
	ans = V
	desire = [i+1 for i in range(V)]

	done = []
	for x in list(powerset(denoms)):
		if sum(x) < V+1:
			done.append(sum(x))
	
	
	missingnumbers = [x for x in desire if not x in done]
	Nmissingnumbers = len(missingnumbers)
	done.sort()
	print done, missingnumbers, Nmissingnumbers
	i = 0
	ans = 0
	
	for x in missingnumbers:
		new = []
		if not x in done:
			denoms.append(x)
			for y in done:
				new.append(y + x)
			ans += 1

		done.extend(new)
	
	return ans

def dosolve(f,g):
	d = f.read().split("\n")
	n = int(d[0])

	j = 1
	for i in range(1,2*n,2):
		print "\n Case no " + str(i/2+1) + "\n"
		data = d[i].split(" ")
		C = int(data[0])
		D = int(data[1])
		V = int(data[2])
		denoms = [int(x) for x in d[i+1].split(" ")]

		g.write ("Case #" + str(i/2 + 1) + ": " + str(solve(C,D,V,denoms)) + "\n")

	return 0
	
def solve_large():
	g = open("A-large-out.txt","w")
	f = open("A-large.in","r")
	dosolve(f,g)

def solve_small():
	g = open("C-small-out-1.txt","w")
	f = open("C-small-attempt1.in","r")
	dosolve(f,g)

def solve_examples():
	g = open("C-eg-out.txt","w")
	f = open("C-eg.in","r")
	dosolve(f,g)
	
# solve_examples()
solve_small()