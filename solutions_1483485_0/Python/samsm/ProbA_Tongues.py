#!/usr/bin/python

import sys
import os
import re

def find_dict(src, dst):
    dict = {'y':'a','e':'o', 'q':'z'}
    for idx in range(len(src)):
        a = src[idx]
        b = dst[idx]
        if a.isalpha():
            if a not in dict:
                dict[a] = b
            elif b != dict[a]:
                print 'wrong map:', a, b

    if len(dict) == 26:
        pass
    elif len(dict) == 25:
        full_set = set(map(chr, range(ord('a'), ord('z')+1)))
        set0 = full_set - set(dict.keys())
        set1 = full_set - set(dict.values())
        dict[list(set0)[0]] = list(set1)[0]
    else:
        print 'wrong dict!!!'
    
    return dict

def translate(src,dict):
    dst = ''
    for n in range(len(src)):
        if not src[n].isalpha():
            dst += src[n]
        else:
            dst += dict[src[n]] 
    return dst

def main():
    src = '''ejp mysljylc kd kxveddknmc re jsicpdrysi
rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd
de kr kd eoya kw aej tysr re ujdr lkgc jv
'''

    dst = '''our language is impossible to understand
there are twenty six factorial possibilities
so it is okay if you want to just give up
'''

    dict = find_dict(src, dst)
    ofid = open('A-small-attempt1.out', 'w')

    list = open('A-small-attempt1.in', 'r').readlines()
    total = int(list[0])
    for n in range(total):
        print >> ofid, 'Case #%d: %s' % (n+1, translate(list[n+1].rstrip(),dict)) 

if __name__ == '__main__':
    main()
