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
    [K, C, S] = line.split()
    [K, C, S] = [int(K), int(C), int(S)]

    print "Case #" + str(case_num+1) + ":",
    val = 1
    while val <= K**C:
        print val,
        val += K**(C-1)
    print

