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
    # Actually, I think the way to think of this is as the numerically ordered
    # list of K^C C-digit numbers in base K.
    # So we can just make a number with the first C digits, then one with the
    # second C digits, etc., and if we have fewer than C digits left at the
    # end, we can fill in with 0s.
    # BUT, their index is going to be 1-up, so whatever number we make, we need
    # to add one
    if S*C < K:
        print "IMPOSSIBLE"
    else:
        picks = []
        digit_to_use = 0 
        next_pick = 0
        next_pick_length = 0
        # We need to use 0 ... K-1
        while digit_to_use < K:
            next_pick = next_pick*K + digit_to_use
            next_pick_length += 1
            digit_to_use += 1
            if next_pick_length == C:
                picks.append( next_pick )
                next_pick = 0
                next_pick_length = 0
        # If we reach this point and we are working on a next pick, we can
        # just assume the rest of the positions are 0, so leave it as is
        if next_pick_length > 0:
            picks.append( next_pick )
        # Now we do the indexing issue
        picks = [x + 1 for x in picks]
        if len(picks) > S:
            print("PROBLEM")
        # Now we print
        for x in picks:
            print x,
        print


