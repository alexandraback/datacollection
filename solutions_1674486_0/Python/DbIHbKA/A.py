#!/usr/bin/env python
# coding:utf-8

def BFS(G, s, n):
        Q = []
        was = []
        Q.append(s)
        while Q != []:
        	cur = Q.pop(0)
        	if cur in was:
        		return "Yes"
        	else:
        		was.append(cur)
        	for x in xrange(n):
        		if G[cur][x] != 0:
        			Q.append(x)
        return "No"

if __name__ == "__main__":
	with open('input.txt','r') as fin:
		with open('output.txt','w') as fout:
			t = int(fin.readline())
			for i in xrange(t):
				n = int(fin.readline())
				G = [[0 for u in xrange(n)] for v in xrange(n)]
				for j in xrange(n):
					_temp = map(int, fin.readline().split(' '))
					for q in xrange(1,len(_temp)):
						G[j][_temp[q]-1] = 1
				ans = 'No'
				for j in xrange(n):
					if BFS(G, j, n) == "Yes":
						ans = "Yes"
						break
				fout.write("Case #{0}: {1}\n".format(i+1, ans))


