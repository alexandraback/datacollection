#!/usr/bin/python

import sys
import math

target = [
    "ejp mysljylc kd kxveddknmc re jsicpdrysi",
    "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd",
    "de kr kd eoya kw aej tysr re ujdr lkgc jv",
]

source = [
    "our language is impossible to understand",
    "there are twenty six factorial possibilities",
    "so it is okay if you want to just give up",
]

transform = dict()
if __name__=="__main__":
    transform['z'] = 'q'
    transform['q'] = 'z'
    transform[' '] = ' '
    for t,s in zip(target,source):
        for tc,sc in zip(t,s):
            if tc == ' ' or tc == '\n':
                continue
            if tc not in transform:
                transform[tc] = sc
            elif transform[tc] != sc:
                print "ALERT - multi-map:",tc,transform[tc],sc
    data = sys.stdin.readlines()
    for i, line in enumerate(data[1:]):
        print "Case #%d:" %(i+1),
        sys.stdout.write(' ')
        for c in line.strip():
            sys.stdout.write(transform[c])
        sys.stdout.write("\n")  
    #keys = list(transform.keys())
    #keys.sort()
    #for tc in keys:
        #print tc,transform[tc]
    #print len(transform)
