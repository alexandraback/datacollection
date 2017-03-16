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
    [max_shyness, shyness_string] = line.split()
    max_shyness = int(max_shyness)
    shyness_counts = [int(x) for x in shyness_string]
    total_standing=0
    num_needed = 0
    for j in range(max_shyness+1):
        if shyness_counts[j] > 0 and total_standing < j:
            num_needed += (j-total_standing)
            total_standing = j+shyness_counts[j]
        else:
            total_standing += shyness_counts[j]


    print "Case #" + str(i+1) + ":", str(num_needed)

