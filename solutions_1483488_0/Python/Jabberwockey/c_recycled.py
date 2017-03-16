#!/usr/bin/python
'''
Created on 14.04.2012

@author: Jens Grabarske
'''

import sys

# A number is only valid (i.e.: comes into consideration as a partner) iff,
# after all the string manipulations, it doesn't start with a 0 and it is
# within A and B (the lower and upper bound)
def valid_str_number(candidate, lowerb, upperb):
    int_num = int(candidate)
    return (candidate[0] != '0') and (lowerb <= int_num <= upperb) 

# Apart from that, all possible pair partners can be generated from a string representation
# by splicing and putting it together.

# Interesting observation: the metric space defined by the number and this
# operation is complete towards this operation. This means practically:
# we only need to look at these numbers once, one pivot element of these
# partners leads to all other possible partners 
def all_possible_combinations(string):
    return set([string[i:] + string[:i] for i in range(len(string))])


# Filtering all the numbers not to be considered, this leaves us with
# the possible partners with the given number.
def possible_partners(num, lowerb, upperb):
    snum = str(num)
    ffun = lambda x: valid_str_number(x,lowerb,upperb)
    return map(int,filter(ffun, all_possible_combinations(snum)))

# Within this list / set of partners, the number of pairs is the sum of all integers up
# to len(partners) - 1. This calls for the Gauss formula.
def sum_range(n):
    return n * (n + 1) / 2

# Putting it together, we can loop from lowerb to upperb. If we haven't seen a number yet,
# we can generate all possible partners and add the number of pairs (between the number and
# the partners and within the partners themselves) to the count - which, as mentioned above,
# is the Gauss formula. Then we mark every partner as already seen.
def recycling(lowerb, upperb):
    c = {}
    count = 0
    for i in range(lowerb, upperb + 1):
        if not c.has_key(i):
            partners = possible_partners(i, lowerb, upperb)
            count += sum_range(len(partners) - 1)
            for partner in partners:
                c[partner] = True
                
    return count

def treat_line(no, line):
    lowerb, upperb = line.split(" ")
    print "Case #" + str(no) + ":", recycling(int(lowerb), int(upperb))

if __name__ == '__main__':
    number = int(sys.stdin.readline())
    for i in range(1,number + 1):
        treat_line(i, sys.stdin.readline())
