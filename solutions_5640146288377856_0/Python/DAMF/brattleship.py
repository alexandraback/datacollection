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
    [R, C, W] = [int(x) for x in line.split()]

    # First we need to figure out what it takes to get it on the right row (or pinned down)
    num_moves_to_pin = C//W
    num_moves_to_finish_off = W-1
    if C%W:
        num_moves_to_finish_off += 1
    total_moves = num_moves_to_pin*R + num_moves_to_finish_off


    #print( "{} {} {}".format(R,C,W))
    print "Case #" + str(case_num+1) + ":", total_moves

