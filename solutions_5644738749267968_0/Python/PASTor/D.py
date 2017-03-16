#!/usr/bin/python

import sys

T = int(sys.stdin.readline())

counter = 1
for i in range(0,T):
    N = int(sys.stdin.readline())
    
    Naomi = map(float, sys.stdin.readline().strip().split())
    Ken = map(float, sys.stdin.readline().strip().split())
    
    Naomi.sort()
    Ken.sort()
    
    Naomi.append(1.0)
    Ken.append(1.0)

    war = 0
    j = 0
    for g in range(0,N):
        wood = Naomi[g]
        while wood > Ken[j]:
            j += 1
        
        if j < N:
            # Ken have a response
            war += 1
            j += 1
        else:
            break
            
    war = N-war
 
    dwar = 0
    j = 0
    for g in range(0,N):
        wood = Ken[g]
        while wood > Naomi[j]:
            j += 1
        
        if j < N:
            # Naomi have a response
            dwar += 1
            j += 1
        else:
            break
            
    
    print 'Case #{}: {} {}'.format(counter, dwar, war) 
    counter += 1
    
    
    