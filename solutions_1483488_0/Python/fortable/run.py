#!/usr/bin/pypy

import sys

def moves(n):
		res = [n]
		for i in range(1, len(str(n))):
				res.append(int(str(n)[i:] + str(n)[:i]))
		res = list(set(res))
		return res

def solve(a, b):
		res = 0
		for i in range(a,b):
				res += len(filter(lambda x: x<= b and x > i, moves(i)))
		return res

if __name__ == "__main__":
		n = sys.stdin.readline()
		data = sys.stdin.readlines()
		c = 1
		for i in data:
				a, b = map(lambda x: int(x), i.split(' '))
				print "Case #"+str(c)+": "+str(solve(a, b))
				c+=1
