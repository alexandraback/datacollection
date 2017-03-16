#!/usr/bin/env python

import sys

res = []

def Solve(E, R, N, v, energy, gain):
    global res
    if energy > E: energy = E
    #print E, R, N, v, energy, gain

    if v:
        x = v[0]
        for i in range(energy+1):
            if energy-i >= 0:
                res.append(Solve(E, R, N, v[1:], energy-i+R, gain+i*x))
            else: break
    else:
        return gain


def main():
    global res
    infile = open(sys.argv[1], 'r')
    inp = infile.readlines()
    T = int(inp[0])
    strn = 1
    for i in range(T):
        (E, R, N) = map(int, inp[strn].split())
        v = map(int, inp[strn+1].split())
        strn += 2
        res = []
        Solve(E, R, N, v, E, 0)
        #print res
        print 'Case #'+str(i+1)+': '+str(max(res))
   


if __name__=='__main__':
    main()
