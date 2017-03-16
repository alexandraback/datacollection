# -*- coding: utf-8 -*-

import sys
fin = sys.stdin
T = int(fin.readline())

            
def solve(b, index_b, t, index_t, level=0):
    level += 1
    if index_b*2==len(b) or index_t*2==len(t): 
        return 0
    
    val = 0    
    if b[index_b*2+1] == t[index_t*2+1]:
        m = min(b[index_b*2], t[index_t*2])
        b[index_b*2] -= m
        t[index_t*2] -= m
         
        if b[index_b*2] == 0:
            index_b += 1 
        if t[index_t*2] == 0:
            index_t += 1
       
        val += m + solve(b,index_b,t,index_t, level)
    else:
        if (index_b+1)*2 == len(b):
            val += solve(b,index_b, t, index_t+1, level)            
        elif (index_t+1)*2 == len(t):
            val += solve(b,index_b+1, t, index_t, level)            
        else:
            bb = b[:]
            tt = t[:]
            val += max(solve(bb, index_b+1, t, index_t, level), solve(b,index_b, tt, index_t+1, level))
            
    return val
         
for case in range(1,T+1):
    cache = {}
    N, M = map(int, fin.readline().split())
    
    boxes = map(int, fin.readline().split())
    toys = map(int, fin.readline().split())
    
    print "Case #%d: %d" % (case, solve(boxes, 0, toys, 0))
    