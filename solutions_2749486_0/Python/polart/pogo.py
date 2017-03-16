#!/usr/local/bin/python2.7
# encoding: utf-8
'''
Created on 12 May 2013

@author: Artem
'''
from __future__ import division
from math import sqrt
import os
import sys
import time
import math

def find(path, p):
    #dir = path.pop()
    dir = path[0]
    del path[0]
    if dir[1] == p:
        return dir
    l = len(dir[0]) + 1
    #xl = abs(dir[1][0] - p[0])
    #yl = abs(dir[1][1] - p[1])
    if l <= 500:
        if p[0] >= 0:
            if dir[1][0] + l <= p[0]:
                path.append( [dir[0] + ['E'], (dir[1][0]+l, dir[1][1])] )
                path.append( [dir[0] + ['W'], (dir[1][0]-l, dir[1][1])] )
        elif p[0] < 0:
            if dir[1][0] - l >= p[0]:
                path.append( [dir[0] + ['E'], (dir[1][0]+l, dir[1][1])] )
                path.append( [dir[0] + ['W'], (dir[1][0]-l, dir[1][1])] )
        if p[1] >= 0:
            if dir[1][1] + l <= p[1]:
                path.append( [dir[0] + ['N'], (dir[1][0], dir[1][1]+l)] )
                path.append( [dir[0] + ['S'], (dir[1][0], dir[1][1]-l)] )
        elif p[1] < 0:
            if dir[1][1] - l >= p[1]:
                path.append( [dir[0] + ['N'], (dir[1][0], dir[1][1]+l)] )
                path.append( [dir[0] + ['S'], (dir[1][0], dir[1][1]-l)] )
                
    return find(path, p)

def write_case(f_out, out, k):
    out = "Case #%d: %s\n" % (k, out)
    f_out.write(out)
    print out

def solve(f_in, f_out):
    T = f_in.readline()
    if not T:
        print 'The input file is empty!'
        sys.exit()
    T = int(T)
    
    for k in xrange(1, T+1):
        X, Y = [int(x) for x in f_in.readline().split()]
        print X, Y    
        xx, yy = X, Y
        #X = abs(X)
        #Y = abs(Y)
        
        #path = [ [['E'], (1,0)], [['N'], (0,1)], [['W'], (-1,0)], [['S'], (0,-1)] ]
        #kk = find(path, (X, Y))
        l = 1
        px = 0
        py = 0
        path = []
        if True:
            while px != X:
                if px + l <= X:
                    px += l
                    path.append('E')
                else:
                    px -= l
                    path.append('W')
                l += 1
            while py != Y:
                if py + l <= Y:
                    py += l
                    path.append('N')
                else:
                    py -= l
                    path.append('S')
                l += 1
        
        ss = ''.join(path)
        #for s in ss:
        #    if 
        out = ss
        print len(ss)
        write_case(f_out, out, k)

def main():
    START = time.time()
    my_dir = os.getcwd()
    name = os.path.basename(__file__)[:-3:]
    
    file_in = "%s\\input\\%s.in" % (my_dir, name)
    file_out = "%s\\output\\%s.out" % (my_dir, name)
    with open(file_in, 'a+') as f_in:
        with open(file_out, 'w') as f_out:
            solve(f_in, f_out)
    
    print 'All done in %f s' % (time.time()-START)
    
if __name__ == '__main__':
    main()