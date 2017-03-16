#! /usr/bin/env python

#import math

#  +---+---+---+
#  | a | b | c |
#  +---+---+---+
#  0   1   2   3
# -3  -2  -1

# int ( input() )
# L = map ( int, input().split() )
# sum (... for i,y in enumerate(L))
# L[:] # list copy
# L1 + L2 # list concatenation
# set(), list()
# F = [i for i, v in enumerate(L) if v == ...]
# L.remove(element)

T = int( input() )

for x in range(1,T+1):
     
    P, Q = map (int, input().split('/') )
    
    g = 0
    good = 0
    k = -1
    while (k < 0):
        g = g + 1
        k = (pow(2,g) * P / Q) - 1

    good = g    
    while (g < 40):
        g = g + 1
        k = (pow(2,g) * P / Q) - 1
        #print(k)
    
    if (k == int(k)):
        print('Case #%i: %i' % (x,good))
    else:
        print('Case #%i: impossible' % (x))
