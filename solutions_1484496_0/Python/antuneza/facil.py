#!/usr/bin/python

import sys
import itertools
def findsubsets(S,m):
    return set(itertools.combinations(S, m))

def findsame(s, n):
	mapa = {}
        for k in range(1,n+1):
                x = findsubsets(s, k)
                for ele in x:
                        suma = sum(ele)
                        if suma in mapa:
				mystr = ""
				for z in ele:
					mystr = mystr + str(z) + " "
				print mystr[0:-1]
				mystr = ""
                                for z in mapa[suma]:
                                        mystr = mystr + str(z) + " "
                                print mystr[0:-1]
				return
			else:
				mapa[suma] = ele
	print "Impossible"
			

def r():
        for line in sys.stdin:
                for tok in line.strip().split():
                        yield tok
inp = r()

t = int(inp.next())
for case in range(t):
	n = int(inp.next())
	s = []
	for i in range(n):
		s.append(int(inp.next()))
	print "Case #" + str(case+1) + ":"
	findsame(s,n)	
