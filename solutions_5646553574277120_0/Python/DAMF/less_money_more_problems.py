#!/usr/bin/python

import sys
import itertools

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

def lowest_missing_value( set_to_search ):
    i = 1
    while i in set_to_search:
        i += 1
    return i

f = open( sys.argv[1] )

num_cases = int(f.readline().split()[0])

for case_num in range(num_cases):
    line = f.readline().strip()
    if len(line) <= 0:
        continue
    [C, D, V] = [int(x) for x in line.split()]
    D_vals = [int(x) for x in f.readline().split()]
    #print("D_vals started as {}".format(D_vals))

    # First we do it the slow way
    all_values = set([])
    for i in range(1,len(D_vals)+1):
        current_combos = itertools.combinations( D_vals, i )
        for combo in current_combos:
            all_values.add(sum(combo))


    #print("All values is {}".format(all_values))
    lmv = lowest_missing_value( all_values )
    while lmv <= V:
        next_denom = lmv
        #print("Adding {}".format(next_denom))
        D_vals.append( next_denom )
        new_possibilities = [next_denom+x for x in all_values]
        for np in new_possibilities:
            all_values.add(np)
        all_values.add(next_denom)
        lmv = lowest_missing_value( all_values )

    num_new_denominations = len(D_vals) - D

    #print( "max is {}".format(V))
    #print( "D vals are {}".format(D_vals))
    print "Case #" + str(case_num+1) + ":", num_new_denominations

