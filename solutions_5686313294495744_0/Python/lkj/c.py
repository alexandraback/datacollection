import itertools

def sufficient(c,l,n1,n2):
	h1 = n1.union(set([x[0] for x in c]))
	h2 = n2.union(set([x[1] for x in c]))
	x1 = set([x[0] for x in l])
	x2 = set([x[1] for x in l])
	return not (len(x1.difference(h1)) or len(x2.difference(h2)))

def bfsize(l,n1,n2):
	if sufficient([],l,n1,n2):
		return len(l)
	for i in range(1,len(l)):
		for c in itertools.combinations(l,i):
			if sufficient(c,l,n1,n2):
				return len(l)-i
	return 0

def solve(l):
	l1 = [x[0] for x in l]
	l2 = [x[1] for x in l]
	d1 = {x: l1.count(x) for x in l1}
	d2 = {x: l2.count(x) for x in l2}
	#print(d1,d2)
	n1 = set()
	n2 = set()
	for x in d1:
		if d1[x] == 1:
			try:
				ind = l1.index(x)
			except:
				continue
			w = l.pop(ind)
			n1.add(w[0])
			n2.add(w[1])
			l1.pop(ind)
			l2.pop(ind)
			#print(x,w)
	for x in d2:
		if d2[x] == 1:
			try:
				ind = l2.index(x)
			except:
				continue
			w = l.pop(ind)
			n1.add(w[0])
			n2.add(w[1])
			l1.pop(ind)
			l2.pop(ind)
	#print(l,n1,n2)
	return bfsize(l,n1,n2)

tc = int(input())
for t in range(1,tc+1):
	n = int(input())
	l = []
	for i in range(n):
		l.append(input().split())
	print('Case #{}: {}'.format(t,solve(l)))
