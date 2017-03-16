#!/usr/bin/python

import sys

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

for i in range(num_cases):
    line = f.readline().strip()
    if len(line) <= 0:
        continue
    [A, B, K] = [int(x) for x in line.split()]
    num_winners = 0
    for first in range(A):
        for second in range(B):
            if first & second < K:
                num_winners += 1


    # If A or B is smaller than K, we have A*B
    # So we can assume K is the smallest
    # We immediately get K*K
    # What extra do we get?
    # Now we're thinking about canceling out the high bits
    # So we can pair every A that is greater than K

    # First, we'll assume that we walk through A
    #for choice in range(A):
        # get the high bit in choice
        # if it's smaller than the high bit in K, we add all of B
        # if it's the same as the high bit in K


    print "Case #" + str(i+1) + ":", num_winners

