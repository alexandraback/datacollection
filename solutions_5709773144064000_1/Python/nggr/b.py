#!/usr/bin/env python
 
from __future__ import print_function
import sys

def read_int():
    return int(input())

def read_float():
    return float(input()) 
 
def read_ls_float():
    s = sys.stdin.readline()
    return [float(x) for x in s.split()]
 
def run(c,f,x):
    ncookies=0
    nfarms=0
    # cookies per second
    rate0=2
    t=0

    #print("// c={0:f},f={1:f},x={2:f}".format(c,f,x))
    step=0
    while ncookies < x:
        # rate0 = 2 + f*nfarms
        # time to get enough money to buy a farm
        tfarm1 = c / rate0
        # Rate of cookie production after buying the next farm
        rate1 = 2 + f*(nfarms+1)

        # time to get enough money to win at the current rate
        twin1 = x / rate0
        # time to get enough money to win if you buy the next farm
        twin2 = tfarm1 + x / rate1
        #print("// [{0:d}] tf={1:12.7f} t2={2:4.1f} t1={3:12.7f} t2={4:12.7f}".format(step, tfarm1, rate1, twin1, twin2))
        if twin2 < twin1:
            # buy this farm and advance to the next step
            t += tfarm1
            nfarms += 1
            rate0 = rate1
        else:
            return t + twin1
        step += 1
    # end while
 
 
def main():
    for i in range(read_int()):
        # input data
        (c,f,x) = read_ls_float()

        result = run(c,f,x) 
 
        # output
        print("Case #%d: %0.7f" % (i + 1, result))
 
if __name__ == "__main__":
    #profile.run('main()')
    sys.exit(main())
