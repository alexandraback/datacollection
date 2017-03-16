#!/usr/bin/python

import sys
from heapq import *

def factorial( n ):
    if n == 0:
        return 1
    else:
        return n*factorial(n-1)


def nchoosek( n, k ):
    #return factorial(n)/(factorial(k)*factorial(n-k))
    answer = 1
    for i in range(1,k+1):
        answer *= (n - (k - i))
        answer /= i
    return answer


f = open( sys.argv[1] )

num_cases = int(f.readline().split()[0])

for case_num in range(num_cases):
    line = f.readline().strip()
    if len(line) <= 0:
        continue
    D = int(line)
    line = f.readline().strip()
    P = [int(x) for x in line.split()]
    if D != len(P):
        print("D != len(P)")

    # Get the Ps into a heap
    P_heap = []
    for P_i in P:
        heappush(P_heap, -1*P_i)

    # You never need to declare num specials to be greater than the highest P, since the highest P
    # is an upper bound on the min number of minutes (realized by just waiting)
    max_P = -1*P_heap[0]
    min_minutes = float("inf")
    for num_specials in range(max_P):
        local_min_minutes = -1*P_heap[0]+num_specials
        if local_min_minutes < min_minutes:
            min_minutes = local_min_minutes
        if min_minutes == 1:
            break
        # Enact special
        stack_to_split = heappop( P_heap )
        if stack_to_split%2 == 0:
            heappush( P_heap, stack_to_split/2 )
            heappush( P_heap, stack_to_split/2 )
        else:
            heappush( P_heap, stack_to_split//2 )
            heappush( P_heap, (stack_to_split//2)+1 )



    print "Case #" + str(case_num+1) + ":", min_minutes

