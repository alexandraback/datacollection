#!/usr/bin/env python

import sys, os, re

#---------------------------------------------------
# Function 
#---------------------------------------------------
def max_cyc(r, T):
    a = 2.0
    b = 2*r-1.0
    c = -T
    d = b*b-4*a*c
    if d < 0.0: return 0
    x = (- b + (d**0.5)) / (2.0 * a)
    x = int(x)
    while 2*x*x+(2*r-1)*x >  T: x -= 1
    while 2*x*x+(2*r-1)*x <= T: x += 1
    x -= 1
    return x 

def load_file(filename):
    dict = {'X':'X won', 'O': 'O won', None:'Game has not completed', 'D':'Draw'}
    with open(filename, 'rU') as f:
        number = int(f.readline())
        for i in range(number):
            r, T = [int(v) for v in f.readline().split()][0:2]
            result = max_cyc(r, T)
            print 'Case #%d: %s' % (i+1, result)
    return

#---------------------------------------------------
# Entry Point 
#---------------------------------------------------
def main():
    #if len(sys.argv) < 3:
    #    print 'Usage:'
    #    print '  %s arg1 arg2' % os.path.basename(sys.argv[0])
    #    sys.exit(1)

    load_file (sys.argv[1])

    return

#---------------------------------------------------
# Unit Test Entry 
#---------------------------------------------------
if __name__ == '__main__':
    main()


