#!/usr/bin/python

import sys
from fractions import gcd

ncases = int(sys.stdin.readline())

def solve(N, M, K, real=0):
    candidate = M * N + 1
    # find the base square
    side = 1
    while 2*(side)**2 - 2*(side) + 1 < K and 2*(side+1)-1 <= M and 2*(side+1)-1 <= N:
        side += 1
    # ok so side is the biggest diamond that fits or that is relevant
    if 2*(side)**2 - 2*side +1 >= K:
        # we have candidate
        if side == 1:
            candidate = 1
        else:
            candidate = 4*side
        #print("first candidate %d" % candidate)
    #print("extended up to side %d" % side)
    if 2*(side)**2 - 2*side +1 >= K:
        # revert to previous best for improvement
        side = side-1
    # now we can try to enlarge previous best if makes sense
    if side > 1:
        size = (2*side-1, 2*side-1)
        psize = size
        cost = 4*(side-1) if side > 1 else 1
        pcost = cost
        covered = 2*(side)**2 - 2*side + 1
        pcovered = covered
        #print(covered, size[0], M, size[1], N)
        while covered < K and (size[0] < M or size[1] < N):
            #print("wanna extend")
            # extend largest dimension first
            if (size[0] < size[1] and size[1] < N) or (size[0] >= M):
                # wanna extend on N
                psize = size
                pcost = cost
                pcovered = covered
                size = (size[0], size[1] + 1)
                cost += 2 if size[0] > 1 else 1
                covered += size[0]
            else:
                # wanna extend on M
                #print("extended")
                psize = size
                pcost = cost
                pcovered = covered
                size = (size[0] + 1, size[1])
                cost += 2 if size[1] > 1 else 1
                covered += size[1]
            #print("extended up to size %d %d cost %d covered %d" % (size[0], size[1], cost, covered))
        # we now have candidate
        if covered >= K:
            candidate = min(cost, candidate)
            #print("second candidate %d" % candidate)
        # we can try to improve, revert to previous if needed
        if (covered >= K):
            cost = pcost
            covered = pcovered
        while covered < K and side > 1:
            #print("doing one extension round")
            for i in range(4):
                covered += side - 1
                cost += 1
                if covered >= K:
                    break
                #print("one hop, cost %d covered %d" % (cost, covered))
            side -= 1
        #print("final cost %d covered %d" % (cost, covered))
        if (covered >= K):
            candidate = min(cost, candidate)
        if real:
            assert(candidate < N*M+1)
    else:
        # special cases
        # either N <= 2 and M <= 2
        # or we want less than 5
        if (K <= 5):
            if (N >= 3 and M >= 3):
                candidate = min(K, 4)
            else:
                candidate = K # can't do better
        else:
            if real:
                assert (N<= 2)
            candidate = K # can't do better

    if real:
        assert(K != 1 or candidate == 1)
    return candidate

for ncase in range(ncases):
    l = sys.stdin.readline().rstrip().split(' ')
    N = int(l[0])
    M = int(l[1])
    if M < N:
        # wlog assume N < M, more cols than lines
        t = M
        M = N
        N = t
    K = int(l[2])
    N2 = max(1, N-1)
    M2 = max(1, M-1)
    result1 = solve(N, M, K, real=1)
    result2 = solve(N2, M, K) if K <= N2*M else result1
    result3 = solve(N, M2, K) if K <= N*M2 else result1
    result4 = solve(N2, M2, K) if K <= N2*M2 else result1
    result = min(result1, min(result2, min(result3, result4)))
    print("Case #%d: %d" % (ncase+1, result))


    
