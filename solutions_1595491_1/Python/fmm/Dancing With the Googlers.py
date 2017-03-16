#!/usr/bin/python
# -*- coding: utf-8 -*-

import sys
import math

lines = sys.stdin.readlines()

T = int(lines[0])

f = [-1 for i in xrange(33)]
g = [-1 for i in xrange(33)]

for i in xrange(11):
	for j in xrange(11):
		for k in xrange(11):
			dif=max(max(i-j,j-i),max(max(i-k,k-i),max(j-k,k-j)))
			if (dif<2): f[i+j+k]=max(f[i+j+k],max(i,max(j,k)))
			if (dif==2): g[i+j+k]=max(g[i+j+k],max(i,max(j,k)))

for caso in xrange(1, T+1):
	token = lines[caso].split()
	n,s,p = int(token[0]),int(token[1]),int(token[2])
	dp = [[0 for i in xrange(111)] for j in xrange(111)]
	for i in xrange(n):
		vote = int(token[i+3])
		for j in xrange(s+1):
			dp[i+1][j] = max(dp[i+1][j], dp[i][j]+(1 if f[vote] >= p else 0))
			dp[i+1][j+1] = max(dp[i+1][j+1], dp[i][j]+(1 if g[vote] >= p else 0))
	print "Case #%d: %d" % (caso,dp[n][s])
