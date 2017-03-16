#!/usr/bin/env python
import sys
import ipdb
from itertools import product
import re

def calc2(ifile):
    out = 0
    k,_,s = [int(x) for x in ifile.readline().replace('\n','').split(' ')]
    keyboard = ifile.readline().strip('\n')
    l = ifile.readline().strip('\n')

    overlap = 0

    for i in range(len(l)-1):
        if l[-(1+i):] == l[:i+1]:
            overlap = i+1
    import ipdb; ipdb.set_trace()
    for letter in l:
        if letter not in keyboard:
            return 0

    if len(l) > s:
        return 0

    possibles = ((s-len(l))/(len(l)-overlap))+1


    matches = 0
    combs = 0
    for word in product(keyboard, repeat=s):
        word = ''.join(word)
        combs += 1
        matches += len([1 for m in re.finditer('(?={})'.format(l), word)])

    import ipdb; ipdb.set_trace()
    return possibles - float(matches)/combs


def calc(ifile):
    out = 0
    k,s,_ = [int(x) for x in ifile.readline().replace('\n','').split(' ')]
    keyboard = ifile.readline().strip('\n')
    l = ifile.readline().strip('\n')

    overlap = 0

    for i in range(len(l)-1):
        if l[-(1+i):] == l[:i+1]:
            overlap = i+1

    for letter in l:
        if l not in keyboard:
            return 0

    if len(l) > s:
        return 0

    possibles = ((s-l)/(l-overlap))+1

    while l[overlap] == l[-1-overlap]:
        overlap += 1


if __name__ == "__main__":
    if len(sys.argv) > 1:
        ifile = open(sys.argv[1])
    else:
        ifile = sys.stdin
    if len(sys.argv) > 2:
        ofile = open(sys.argv[2])
    else:
        ofile = sys.stdout
    for i in range(int(ifile.readline())):
        ofile.write("Case #%i: %s\n" % (i+1, calc2(ifile)))

