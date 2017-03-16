#!/usr/bin/python
'''
Created on 14.04.2012

@author: Jens Grabarske
'''

import sys

# The idea is that the list of top points can be partitioned into
# three groups: points that definitely contain a score equal
# or higher as p, even if they aren't surprising, points that
# definitely don't contain one and points that are "critical"
# in the sense that they may or may not contain a score higher
# than p depending on whether they are surprising or not.

# It turns out that for any given p, there are exactly two
# top points which are critical: p + 2 * (p - 2) and p + 2 * (p - 2) + 1
# as those two can either be achieved by surprising scores
# with p or with normal scores without p.

# For example: for p = 5 the two numbers are 11 and 12. 11 can
# be expressed as either 5+3+3 or as 4+4+3, depending on whether
# it is surprising or not. Likewise, 12 can be expressed as either
# 5+3+4 or 4+4+4. For every top points higher than 13, a score equal
# or higher than 5 is guaranteed to be a member of the set, even if
# it isn't surprising (13 = 5+4+4). Top points < 11 will also
# not contain p, even if they are surprising.

# As the question asks for the maximum number of contestants with
# a score equal or greater than p, the question arises how many of
# these critical top points could be surprising. As the maximum number
# would be s, the maximum number of critical top points that contain
# a score equal or greater than p is min(s,c) with c being the number
# of critical points.

# The main work horse of the program, taking s and p and the list
# of top points. Returns the maximum number of contestants with
# a score equal or greater than p.
def get_max_p_googlers(s, p, lst):
    # The lower critical number
    crit1 = p + 2 * (p - 2)
    
    # The higher critical number
    crit2 = crit1 + 1
    
    # The number of top points that
    # were beyond doubt and contained
    # a score of p or greater (points
    # below crit1 can be ignored)
    no_beyond = 0
    
    # The number of critical top points
    no_crit   = 0
    
    for elm in lst:
        if elm > crit2:
            no_beyond += 1
        elif elm < crit1:
            pass
        
        # A special case: if top points are < 2,
        # they can't be surprising and therefore
        # aren't critical by definition.
        elif elm >= 2:
            no_crit += 1
    
    return no_beyond + min(no_crit, s)

# Takes a line read from a file or stdin, tokenises it,
# converts the strings to integers and uses that to call
# the max_passers function - writing the result to
# stdout
def treat_line(no, line):
    tokens = line.split(" ")
    s = int(tokens[1])
    p = int(tokens[2])
    lst = map(int,tokens[3:])
    print "Case #" + str(no) + ":", get_max_p_googlers(s,p,lst)
    
    
if __name__ == '__main__':
    number = int(sys.stdin.readline())
    for i in range(1,number + 1):
        treat_line(i, sys.stdin.readline())
