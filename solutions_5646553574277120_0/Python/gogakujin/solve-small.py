# coding: utf-8

import os, sys, re, string
import math,random

def solve(c, d, v, coins):
	#print c, d, v, coins
	dp = [0] * (v + 1)
	dp[coins[0]] = 1
	for v1 in coins[1:]:
		for i in xrange(v, 0, -1):
			if i - v1 > 0 and dp[i - v1] == 1:
				dp[i] = 1
		dp[v1] = 1
	res = 0
	#print dp
	for i in xrange(1, v + 1):
		if dp[i] == 0:
			res += 1
			for j in xrange(v, 0, -1):
				if j - i > 0 and dp[j - i] == 1:
					dp[j] = 1
			dp[i] = 1
			coins.append(i)
			#print dp
			#print 'add', i, coins
	return res

def main():
	t = int(sys.stdin.readline().strip())
	for x in xrange(t):
		c,d,v = map(int, sys.stdin.readline().split(' '))
		coins = map(int, sys.stdin.readline().split(' '))
		print "Case #{0}: {1}".format(x + 1, solve(c, d, v, coins))

if __name__ == '__main__':
	main()


