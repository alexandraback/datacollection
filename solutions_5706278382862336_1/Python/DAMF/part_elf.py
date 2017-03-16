#!/usr/bin/python

import sys
import fractions

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
    [P,Q] = [int(x) for x in line.split('/')]
    gcd = fractions.gcd(P,Q)
    num = P/gcd
    den = Q/gcd
    #print num, den


    answer = 0
    if den == 1 or den == 2:
        answer = 1
    else:
        for j in range(40):
            if float(P)/float(Q) >= 1.0/(2**j):
                answer = j
                break

    power_of_two = False
    for j in range(40):
        if 2**j == den:
            power_of_two = True

    if not power_of_two:
        answer = 0

    if answer == 0:
        print "Case #" + str(i+1) + ": impossible"
    else:
        print "Case #" + str(i+1) + ":", answer

