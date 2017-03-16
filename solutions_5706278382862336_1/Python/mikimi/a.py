"""
def gcd(a,b):
    while 1:          # loop until break
        r = a%b        # step 1
        if r == 0:     # step 2
            break      # we're done
        else:
            a,b = b,r  # step 3
	return b
"""
from fractions import gcd
def is_power2(num):
    return num != 0 and ((num & (num - 1)) == 0)

def power_two(n):
    return n.bit_length() - 1

import sys
T = int(sys.stdin.readline())
for case in xrange(1, T+1):
    #print "========================="
    #print "========================="
    #print "another case"
    P, Q = map(int, sys.stdin.readline().split("/"))
    
    #print "P, Q:", P, Q
    
    pq = gcd(P, Q)
    #print "pq:", pq
    P = P/pq
    Q = Q/pq
    
    #print "P, Q:", P, Q
    
    
    if is_power2(Q):
        
        r = power_two(P)
        
        print "Case #"+str(case)+": "+str(Q.bit_length()-1-r)
    else:
        print "Case #"+str(case)+": impossible"
