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

for case_num in range(num_cases):
    line = f.readline().strip()
    if len(line) <= 0:
        continue
    N = int(line)
    odd_heights = set()
    for i in range(2*N-1):
        heights = f.readline().strip().split()
        heights = [int(x) for x in heights]
        for height in heights:
            if height in odd_heights:
                odd_heights.remove(height)
            else:
                odd_heights.add(height)
    if len(odd_heights) != N:
        print("PROBLEM!")
    answer = sorted(list(odd_heights))




    print "Case #" + str(case_num+1) + ":",
    for val in answer:
        print val,
    print

