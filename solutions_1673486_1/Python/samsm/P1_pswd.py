#!/usr/bin/python

import sys
import os
import re

def run(a, b, list):
    prob0 = []
    prob = []
    p = 1.0
    for i in range(a):
        p = p * list[i] 
        prob0.append (p)

    prob.append (1.0 - prob0[0])
    for i in range(a-1):
        prob.append (prob0[i] - prob0[i+1])
    prob.append (prob0[a-1])

    # cost
    cost = []

    # continue
    c = (b-a+1)*prob[-1] + (b-a+1+b+1)*(1-prob[-1])  
    cost.append(c)

    # retry
    cost.append (1+b+1)

    # back
    for back in range(a+1):
        p = sum(prob[-back-1:])
        c = (back*2+b-a+1)*p + (back*2+b-a+1+b+1)*(1-p)
        cost.append(c)
    
    return min(cost)

def load_input(filename):
    f = open(filename, 'r')
    N = int(f.readline())
    list = []
    for i in range(N):
        array = map(int, f.readline().split())
        a, b = array[0:2]
        array = map(float, f.readline().split())
        list.append( [a, b, array[0:a]])
    return list


def main():
    #print run (2, 5, [0.6, 0.6])
    #print run (1, 20, [1])
    #print run (3, 4, [1, .9, .1])

    #infile = 'A-large.in'
    #outfile = 'A-large.out'
    #infile = 'A-test.in'
    #outfile = 'A-test.out'
    #infile = 'A-small-attempt0.in'
    #outfile = 'A-small-attempt0.out'
    infile = 'A-large.in'
    outfile = 'A-large.out'

    list = load_input(infile)
    fid = open(outfile, 'w')

    for n in range(len(list)):
        vec = list[n]
        a, b, array = vec[0:3]

        result = run(a, b, array) 
        print >> fid, 'Case #%d: %f' % (n+1, result)

if __name__ == '__main__':
    main()
