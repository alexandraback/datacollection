#!/usr/bin/python
'''
Created on 28.04.2012

@author: Jens Grabarske
'''

import sys

# The following formula can be used: given that p is the probability
# that so far, the typed letters are all correct - what is the expected
# value of keystrokes?
def expected_value(a,b,p):
    return 2 * b - a + 2 - p * (b + 1)

def password_estimate(a,b,plist):
    p = 1
    minv = b + 2
    for x in range(a + 1):
        if x > 0:
            p *= plist[x - 1]
            
        minv = min(minv, (a - x) + expected_value(x, b, p))
        
    return minv

def treat_case(no,line1,line2):
    a, b = map(int,line1.split(" "))
    plst = map(float,line2.split(" "))
    print "Case #" + str(no) + ":", password_estimate(a, b, plst)



if __name__ == '__main__':
    number = int(sys.stdin.readline())
    for i in range(1,number + 1):
        treat_case(i, sys.stdin.readline(), sys.stdin.readline())
    

