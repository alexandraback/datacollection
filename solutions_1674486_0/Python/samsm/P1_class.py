#!/usr/bin/python

import sys
import os
import re

def check(dict):
    for key in dict:
        if check_diag(dict, key):
            return True 
    return False 

def check_diag(dict,node):
    seek = {}
    list = [node]
    while len(list)>0:
        #print seek, list
        s = list.pop()
        if s in seek:
            #print 'Diag', node, d
            return True
        for d in dict[s]:
            if d in seek:
                #print 'Diag', node, d
                return True
            list.append(d)
        seek[s] = 1
    return False 

def write_dot(idx,dict):
    filename = 'dot%d.dot' % idx
    f = open(filename, 'w')
    print >> f, 'digraph G {'
    for k in dict.keys():
        for v in dict[k]:
            print >> f, '%d->%d;' % (k, v)
    print >> f, '};'

def load_input(filename):
    f = open(filename, 'r')
    N = int(f.readline())
    list = []
    for i in range(N):
        M = int(f.readline())
        dict = {}
        for j in range(M):
            array = map(int, f.readline().split())
            dict[j+1]=array[1:]
        list.append(dict)
    return list

def main():
    #print run (2, 5, [0.6, 0.6])
    #print run (1, 20, [1])
    #print run (3, 4, [1, .9, .1])

    #infile = 'A-large.in'
    #outfile = 'A-large.out'
    #infile = 'A-test.in'
    #outfile = 'A-test.out'
    infile = 'A-small-attempt2.in'
    outfile = 'A-small-attempt2.out'
    #infile = 'A-large.in'
    #outfile = 'A-large.out'

    list = load_input(infile)
    #print check(list[32])
    #print check_diag(list[32],23)
    fid = open(outfile, 'w')

    for n in range(len(list)):
        print '#####', n
        if check(list[n]):
            print >> fid, 'Case #%d: Yes' % (n+1)
        else:
            print >> fid, 'Case #%d: No' % (n+1)

if __name__ == '__main__':
    main()
