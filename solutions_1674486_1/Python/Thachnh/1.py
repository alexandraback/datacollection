#!/usr/bin/python

import sys

f = open("in1.txt","rb")
t = int(f.readline())

for i in range(t):
	n = int(f.readline())
	c = [[0 for ii in range(n)] for jj in range(n)]
	r = [True for ii in range(n)]
	for j in range(n):
		s = map(int,f.readline().split())
		m = s.pop(0)
		for k in range(m):
			c[j][s[k]-1] = 1
			r[s[k]-1] = False

	diamond = False

	for j in range(n):
		if r[j]:
			q = []
			q.append(j)
			visit = [False for ii in range(n)]
			visit[j] = True
			while (len(q) > 0):
				node = q.pop(0)
				for k in range(n):
					if (c[node][k] == 1):
						if (visit[k]):
							diamond = True
							break
						else:
							q.append(k)
							visit[k] = True
				if (diamond):
					break
			if (diamond):
				break
						
	print("Case #{0:0d}:").format(i+1),
	if (diamond):
		print "Yes"
	else:
		print "No"
