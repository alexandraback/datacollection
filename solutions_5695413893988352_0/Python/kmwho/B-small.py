#! /usr/bin/python
# kmwho
# CodeJam 2016  1B

from __future__ import print_function
import math


def __del():
	raw_input()
	int(raw_input())
	map(int,raw_input().split())

def allPos( C ):
	allCs = [ "" ]
	for ci in C:
		if ci == "?":
			newCs = [ s+cj for cj in "0123456789" for s in allCs]
		else:
			newCs = [ s+ci for s in allCs ]
		allCs = newCs
	return [ int(s) for s in allCs ]

def solvecase():
	C,J = input().strip().split()
	allCs = sorted(allPos(C))
	allJs = sorted(allPos(J))
	ans   = ( allCs[0], allJs[0] )
	ansmin = abs( ans[0]-ans[1] )
	for ci in allCs:
		for ji in allJs:
			diff = 	abs(ci-ji)
			if diff < ansmin:
				ans = (ci, ji)
				ansmin = diff
	return " ".join( map(lambda x: str(x).zfill(len(C)), ans ) )

def solve():
    T  = int(input())
    for t in range(1,T+1):
        res = solvecase()
        print( "Case #" + str(t) + ": " + str(res) )

def main():
	solve()


main()
