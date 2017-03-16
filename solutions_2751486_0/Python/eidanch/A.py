
from sys import stdin

def isvowel(c):
	return c == "a" or c == "e" or c == "i" or c == "u" or c == "o"

def ccons(name, n):
	longest = 0
	curr = 0
	prev = 1
	for i in range(0,len(name)):
		if isvowel(name[i]):
			prev = 0
			longest = max(curr,longest)
		elif prev == 1:
			curr += 1
		else:
			curr = 1
			prev = 1
	return max(longest,curr) >= n

def nval(name, n):
	k = len(name)
	sum = 0
	for i in range(0,k + 1 - n):
		for j in range(i+n,k+1):
			if ccons(name[i:j],n):
				sum +=1
	return sum

	
T = int(stdin.readline())
for i in range(0,T):
	ls = stdin.readline().split(" ")
	name = ls[0]
	n = int(ls[1])
	res = nval(name, n)
	print "Case #{0}: {1}".format(i+1, res)
