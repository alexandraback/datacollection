import numpy as np
import itertools

def solve(a,b):
	solution = [[]]*a
	if b > 1+(a-2)*(a-1)/2:
		return "IMPOSSIBLE"
	else:
		for s in xrange(a):
			solution[s] = ["0"]*a
		solution[0] = ["1"]*a
		helper = [0]*a
		d = int(b-1)
		while True:
			if sum(helper) == b-1:
				break
			for i in range(a):
				helper[i] = min(a-(i+2), d)
				d = d -min((a-(i+2)),d)
				if d == 0:
					break
		for t in xrange(a):
			n = helper[t]
			for x in xrange(1,n+1):
				solution[x][a-(t+1)] = "1"
		for k in range(a):
			solution[k][k] = "0"
	
		return "POSSIBLE" + "\n" + "\n".join(["".join(t) for t in solution])
		


t = int(raw_input())
for i in xrange(1, t + 1):
	a,b = [int(t) for t in raw_input().split(" ")]
	print "Case #{}: {}".format(i, solve(a,b))
