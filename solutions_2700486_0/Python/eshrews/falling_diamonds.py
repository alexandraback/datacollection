#!/usr/bin/python

import fileinput


c = {}
def choose(nn, kk):
    if((nn, kk) in c):
        return c[(nn,kk)]

    if(kk== 0):
        return 1
    if(nn == 0):
        return 0
    if(kk > nn):
        return 0
    
    res = choose(nn-1, kk-1) + choose(nn-1, kk)
    c[(nn,kk)] = res
    return res

case = 1
for linenum, line in enumerate(fileinput.input()):
    if linenum == 0:
        cases = int(line)
        continue

    case = linenum
    N, X, Y = [int(x) for x in line.split()]
    X = abs(X)

    stack_size = 0
    result = 0.0

    while(N - (2* stack_size) - 1 >= 0):
        N -= ((2 * stack_size) + 1)
        stack_size += 2


    if(X+Y < stack_size):
        result = 1.0
    elif(X+Y > stack_size or X == 0 or Y > N):
        result = 0.0   
    else:
        n, k = N, Y+1
        if(N > stack_size):
            n -= (N - stack_size) * 2
            k -= (N - stack_size)
        ways = 0
        ck = n
        
        while ck >= k:
            ways += choose(n, ck)
            ck -= 1


        result = ways / (2.0**n)


    print "Case #{0}: {1}".format(case, result)

    if case == cases:
        break
