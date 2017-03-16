#!/usr/bin/python

import sys
import os
import re

def check_type(points):
    X = sum(points)
    total = 2.*X
    length = len(points)

    pts = points[:]
    pts.sort()
    pts.reverse()
    for idx in range(length):
        avg = total/(length-idx)
        total -= pts[idx]
        if pts[idx] >= avg:
            continue
        return pts[idx], avg
    return pts[0]+1, 0. 

def run(points):
    X = sum(points)
    limit, avg = check_type(points)
    list = []

    for idx in range(len(points)):
        pt = points[idx]
        if pt > limit:
            list.append(0.0)
        else:
            list.append((avg-pt)/X*100.)
    return list

def load_input(filename):
    f = open(filename, 'r')
    N = int(f.readline())
    list = []
    for i in range(N):
        array = map(int, f.readline().split())
        list.append( [array[0], array[1:]])
    return list

def main():
    #print run (2, 5, [0.6, 0.6])
    #print run (1, 20, [1])
    #print run (3, 4, [1, .9, .1])

    #infile = 'A-large.in'
    #outfile = 'A-large.out'
    #infile = 'A-test.in'
    #outfile = 'A-test.out'
    infile = 'A-small-attempt0.in'
    outfile = 'A-small-attempt0.out'
    infile = 'A-large.in'
    outfile = 'A-large.out'

    list = load_input(infile)
    fid = open(outfile, 'w')

    for n in range(len(list)):
        idx, pts = list[n]
        result = run(pts) 
        print >> fid, 'Case #%d: ' % (n+1),
        for r in result:
            print >> fid, '%f' % r,
        print >> fid, ''

if __name__ == '__main__':
    main()
