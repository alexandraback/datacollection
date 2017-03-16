#-------------------------------------------------------------------------------
# Name:        module1
# Purpose:
#
# Author:      hken
#
# Created:     27/04/2013
# Copyright:   (c) hken 2013
# Licence:     <your licence>
#-------------------------------------------------------------------------------
#!/usr/bin/env python

import math

def main():
    ntest = int(input())
    for i in range(1, ntest+1):
        r, t = [int(x) for x in input().split()]
        x = int(math.floor( 0.25 *(math.sqrt(t*8 + (r+r-1)*(r+r-1)) - (r+r-1)) ))

        # adjust
        while ((2*x*x + (r+r-1)*x) > t):
            x = x - 1
        while ((2*(x+1)*(x+1) + (r+r-1)*(x+1)) <= t):
            x = x + 1

        print("Case #" + str(i) + ": " + str(x))



if __name__ == '__main__':
    main()
