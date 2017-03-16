#!/usr/bin/python

def get(f=int):
	return map(f, raw_input().split())

T, = get()

for test in range(1,T+1):
	A, B, K = get()
	count = 0
	for i in range(A):
		for j in range(B):
			if (i & j) < K:
				count += 1
	print "Case #%d: %d" % (test, count)