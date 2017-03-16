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
    pancakes = line
    current_num_flips = 0
    for i in range(len(pancakes)):
        if (current_num_flips%2 == 0 and pancakes[len(pancakes)-1-i] == '-') or (current_num_flips%2 == 1 and pancakes[len(pancakes)-1-i] == '+'):
            current_num_flips += 1

    print "Case #" + str(case_num+1) + ":", current_num_flips

