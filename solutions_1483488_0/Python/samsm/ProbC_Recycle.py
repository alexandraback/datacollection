#!/usr/bin/python

import sys
import os
import re

def get_number(num): 
    s = str(num)
    list = []
    for i in range(len(s)):
        if s[i] != '0':
            list.append(int(s[i:]+s[0:i]))
    list.sort()
    return list[0]

def get_total_number(start, stop):
    dict = {}
    for n in range(start, stop+1):
        p = get_number(n)
        if p not in dict:
            dict[p] = 1
        else:
            dict[p] += 1
    total = 0
    for n in dict.keys():
        v = dict[n]
        total += (v*(v-1)/2)
    return total

def load_input(filename):
    f = open(filename, 'r')
    N = int(f.readline())
    list = []
    for i in range(N):
        array = map(int, f.readline().split())
        list.append(array[0:2])
    return list

def main():
    infile = 'C-small-attempt0.in'
    outfile = 'C-small-attempt0.out'

    list = load_input(infile)
    fid = open(outfile, 'w')

    for i in range(len(list)):
        vec = list[i]
        pair = get_total_number(vec[0], vec[1])
        print >> fid, 'Case #%d: %d' % (i+1, pair) 

if __name__ == '__main__':
    main()
