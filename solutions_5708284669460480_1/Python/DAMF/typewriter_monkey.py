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

def count_overlapping_copies( search_string, target_string ):
    total = 0
    first_pos = search_string.find( target_string )
    while first_pos >= 0:
        total += 1
        if first_pos == len(search_string)-1:
            search_string = ""
        else:
            search_string = search_string[first_pos+1:]
        first_pos = search_string.find( target_string )
    return total


f = open( sys.argv[1] )

num_cases = int(f.readline().split()[0])

for case_num in range(num_cases):
    line = f.readline().strip()
    if len(line) <= 0:
        continue
    [K, L, S] = [int(x) for x in line.split()]
    keyboard = f.readline().strip()
    target_string = f.readline().strip()
    if len(keyboard) != K or len(target_string) != L:
        print("Input problem!")

    # Maybe I don't have to worry about overlaps because I'm summing over everything
    letter_probs = {}
    for letter in keyboard:
        if letter in letter_probs:
            letter_probs[letter] += (1.0/K)
        else:
            letter_probs[letter] = (1.0/K)

    target_prob = 1.0
    possible = True
    for letter in target_string:
        if letter in letter_probs:
            target_prob *= letter_probs[letter]
        else:
            possible = False
            target_prob = 0.0

    expected_value = target_prob*(S-L+1)
    maximum_overlap = 0
    for i in range(1,L):
        if target_string[-i:] == target_string[:i]:
            maximum_overlap = i

    maximum_bananas = 1 + (S-L)//(L-maximum_overlap)
    if possible:
        result = maximum_bananas - expected_value
    else:
        result = 0.0

    # First, we can do this a super slow way
    # Make all the possible outputs
    #all_strings = [''.join(x) for x in itertools.product( keyboard, repeat=S )]
    #banana_values = [count_overlapping_copies( x, target_string ) for x in all_strings]
    #expected_num_bananas_to_give = sum(banana_values)*1.0/(K**S)
    #max_num_bananas_to_give = max(banana_values)
    #result = max_num_bananas_to_give - expected_num_bananas_to_give


    print "Case #" + str(case_num+1) + ":", "%0.9f" % result

