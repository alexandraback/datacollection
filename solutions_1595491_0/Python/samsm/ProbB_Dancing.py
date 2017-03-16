#!/usr/bin/python

import sys
import os
import re

def load_input(filename):
    f = open(filename, 'r')
    N = int(f.readline())
    list = []
    for i in range(N):
        array = map(int, f.readline().split())
        num, sup, thr = array[0:3]
        list.append([sup, thr, array[3:3+num]])
    return list

def proc(N,s,p,list):
    thr0 = (N-1)*(max([0,p-1]))+p
    thr1 = (N-1)*(max([0,p-2]))+p
    n0 = 0
    n1 = 0
    for v in list:
        if   v >= thr0: n0 += 1
        elif v >= thr1: n1 += 1
    #print p, ':', thr0, thr1, ':', n0, n1, ':', list 
    
    if n1 > s:  n0 += s
    else:       n0 += n1 

    return n0 

def main():
    infile = 'B-small-attempt1.in'
    outfile = 'B-small-attempt1.out'

    list = load_input(infile)
    fid = open(outfile, 'w')

    for n in range(len(list)):
        vec = list[n]
        sup, thr, score = vec[0:3]
        est = proc(3,sup,thr,score)
        print >> fid, 'Case #%d: %d' % (n+1, est)



if __name__ == '__main__':
    main()
