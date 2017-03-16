#!/usr/bin/python

import sys

def revert(stack):
	resultat = [1-s for s in stack]
	return resultat[::-1]

def solve(stack):
	if (len(stack) == 0):
		return 0
	if (stack[0] == 0):
		i = 1
		while (i < len(stack) and stack[i] == 0):
			i+=1
		if (i < len(stack)):
			tmp = revert(stack[0:i])
			tmp.extend(stack[i+1::])
			return 1+ solve(tmp)
		else:
			return 0
	else:
		i = len(stack)-1
		while (i >= 0 and stack[i] == 0):
			i-=1
		if (i < 0):
			return 0
		return 1+solve(revert(stack[0:i+1]))
	
def main():
	with open(sys.argv[1], 'r') as f:
		t = int(f.readline())
		lines = [f.readline() for i in xrange(t)]
	stacks = [[0 if s == '+' else 1 for s in l[:-1]] for l in lines]
	for i in xrange(len(stacks)):
		print('Case #%d: %d' % (i+1, solve(stacks[i])))

if __name__ == '__main__':
	main()
