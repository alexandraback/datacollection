#!/usr/bin/python

import fileinput

def solve(A, B, K):
	min_n = min(A,B);
	cnt=0;
	for i in xrange(0,A):
		for j in xrange(0,B):
			if (i & j) < K:
				cnt+=1
	return cnt


line_cnt=0
test_cases=1
for line in fileinput.input():
	if(line_cnt > (test_cases)):
		#print 'error'
		break;
	if(line_cnt == 0):
		test_cases=int(line.rstrip());
	else:
		line=line.split();
		A=int(line[0]);
		B=int(line[1]);
		K=int(line[2]);
		ret=solve(A, B, K)
		print 'Case #'+str(line_cnt)+': '+str(ret)
	line_cnt+=1;
