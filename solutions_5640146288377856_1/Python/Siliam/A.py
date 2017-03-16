# -*- coding: utf-8 -*-
from math import ceil

if __name__ == '__main__':
    f = open('A-large.in', 'r')
    o = open('A-large.out', 'w')

    T = int(f.readline())
    
    for testCase in xrange(1, T + 1):
        R, C, W = map(int, f.readline().split())
        r = 0
        
        if(C == W or W == 1):
            r = C
        else:
            if(W >= (C+1)/2):
                r = 1 + W
            else:
                r = ceil(float(C)/float(W)) + W - 1
        
        r *= R
        o.write('Case #' + str(testCase) + ': ' + str(int(r)) +'\n')
    o.close()