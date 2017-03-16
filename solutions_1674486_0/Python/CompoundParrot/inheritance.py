#!/usr/bin/env python
# encoding: utf-8
"""
CODEJAM TEMPLATE

Created by Jamie Smith

NOTE: THIS CODE IS WRITTEN IN SAGE

"""

import sys
import os
from numpy import *
	
def readints(f):
	return map(int, f.readline().split())


def main():
	os.chdir("/Users/Jamie/Documents/Codejam")
	
	f=open('input.txt','r')
	f=open('A-small-attempt1.in','r')
	# f=open('A-large.in','r')
	o=open('inherit.txt','w')
	
	T=int(f.readline())

	for j in range(T):
		N=int(f.readline())
		G=DiGraph(N)
		for i in range(N):
			L=readints(f)
			m=L.pop(0)
			for k in range(m):
				G.add_edge(i,L.pop(0)-1)
		
		diamond=False
		for x in range(N):
			if diamond:
				break
			for y in range(N):
				if diamond:
					break
				if len(G.all_simple_paths(starting_vertices=[x], ending_vertices=[y]))>1:
					diamond=True
		
		if diamond:
			result='Yes'
		else:
			result='No'

		
		
		
		print "Case #%s: %s\n" % (j+1,result)
		o.write("Case #%s: %s\n" % (j+1,result))
	f.close()
	o.close()

if __name__ == '__main__':
	main()


