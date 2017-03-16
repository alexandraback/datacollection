#!/usr/bin/python
# -*- coding: utf-8 -*-

from fractions import gcd



def trouver(p,q):
    if (p == 1 and q == 1):
        return 0
    if (2*p >= q):
        return 1
    return 1+trouver(2*p,q)

    '''
    #print "test %d %d" % (p,q)
    #if (p == 0):
    #    return 10000000
    if (q == 1 and p == 1):
        return 0
    p1 = p / 2
    p2 = p1 + 1
    qq = q / 2
    g1 = gcd(p1,qq)
    g2 = gcd(p2,qq)
    p1 /= g1
    q1 = qq / g1
    p2 /= g2
    q2 = qq / g2
    print "%d/%d → %d/%d et %d/%d" % (p,q,p1,q1,p2,q2)
    if (q1 <= q2 and p1 <> 0):
        return 1 + trouver(p1,q1)
    return 1 + trouver(p2,q2)
    #return 1 + min(trouver(p1,q1),trouver(p2,q2))
    '''

def verif(q):
    if (q == 0):
        print "BUG MASSIF"
        return False
    elif (q % 2 == 0):
        return verif(q/2)
    elif (q <> 1):
        return False
    return True

nbcases = int(raw_input())

for case in xrange(1,nbcases+1):
    [p,q] = [eval (n) for n in raw_input().strip().split("/")]
    g = gcd(p,q)
    p /= g
    q /= g
    if not verif(q):
        print "Case #%d: impossible" % case
    else:
        print "Case #%d: %d" % (case,trouver(p,q))

