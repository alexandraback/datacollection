import sys

from collections import defaultdict

# http://blog.bjrn.se/2008/04/lexicographic-permutations-using.html
from next_permutation import *

def anal(ts,p) :
    reachable = ( (p<=ts/3+1 ) if ts%3!=0 else (p<=ts/3) )
    if ts%3==0 :
	reachableSurp = (p<=ts/3+1 ) # 6 = 1 2 3
	if ts==0 :
	    reachableSurp = (p==0)
    elif ts%3==1 :
	reachableSurp = (p<=ts/3+1 ) # 4 = 1 1 2
    else :
	reachableSurp = (p<=ts/3+2 ) # 5 = 1 1 3
    if reachable :
	assert reachableSurp
    return reachable,reachableSurp

def case() :
    a = map(int, sys.stdin.readline().split() )
    n = a[0]
    s = a[1]
    p = a[2]
    a = a[3:]
    assert n==len(a)
    rN = 0
    rsN = 0
    for ts in a :
	reachable,reachableSurp = anal(ts,p)
#	print reachable,reachableSurp,ts,p
	rN += int(reachable)
	rsN += int(reachableSurp)
#    print rN,rsN
    return rN+min((rsN-rN,s))

t = int(sys.stdin.readline())
for testNr in range(1,t+1) :
    print "Case #%d:" % testNr ,
    print case()
