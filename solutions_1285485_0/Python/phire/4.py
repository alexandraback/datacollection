#!/usr/bin/python2
# -*- coding: utf-8 -*-

import sys
import os

def check(x, d):
    return 1 if x <= d else 0

def farthest(d, m):
    return (d/m + 1) * m

def gooddist(x,y,cx,cy,d):
#    x=2*x+1
#    y=2*y+1
#    cx*=2
#    cy*=2
#    d = 4*d*d
    return 4*((x-cx)*(x-cx)+(y-cy)*(y-cy)) <= d*d

def gcd(a,b):
    while b:
       a, b = b, a % b
    return a

def get_direction(x, y):
    d = gcd(abs(x),abs(y))
#    print (x/d, y/d)
    return (x/d, y/d)

def mirror(c, x, m):
    return m - x if c % 2 else x

def solve(y, x, w, h, d):
    ret = 0
#    print
#    print y, x, w, h, d
#    ret += check(2*x+1, d)
#    ret += check(2*y+1, d)
#    ret += check(2*(h-y-1)+1, d)
#    ret += check(2*(w-x-1)+1, d)
#    ret += check(x*2, d)
#    ret += check(y*2, d)
#    ret += check(2*(h-y-1), d)
#    ret += check(2*(w-x-1), d)
    s = set()
    for cx in xrange(-farthest(d,w), d+w+1, w):
        for cy in xrange(-farthest(d,h), d+h+1, h):
            if (gooddist(x,y,cx,cy,d)):
#                print "Add", cx, cy
                s.add(get_direction(cx-x, cy-y))

    for i in xrange(-d/w - 50, d/w + 50):
        for j in xrange(-d/h - 50, d/h + 50):
            if i == 0 and j == 0:
                continue
            cx = i * w + mirror(i, x, w)
            cy = j * h + mirror(j, y, h)
            if (gooddist(x,y,cx,cy,2*d)):
#                print "Add", cx, cy
                s.add(get_direction(cx-x, cy-y))
    return len(s)

def main():
    T = int(sys.stdin.readline())
    for i in xrange(1, T+1):
        W, H, D = map(int, sys.stdin.readline().strip().split())
        for j in xrange(W):
            line = sys.stdin.readline()
            if 'X' in line:
                y = j
                x = line.find('X')

        W-=2; W*=2
        H-=2; H*=2
        x-=1; x*=2; x+=1
        y-=1; y*=2; y+=1
        D*=2
        print "Case #" + str(i) + ":", str(solve(y,x,W,H,D))

if __name__ == '__main__':
    main()
