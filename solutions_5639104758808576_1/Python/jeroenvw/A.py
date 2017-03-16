#!/usr/bin/python

from __future__ import division

import sys, os, subprocess
from pprint import pprint

def line():
    return FD.readline().strip()

def doit():
    N = int(line())
    for i in range(N):
        print 'Case #%d: %s' % (i+1, go())

def go():
    S = []
    for c in line().split()[1]:
        S.append(int(c))
    #pprint(S)

    clappers = 0
    friends = 0
    for i, cnt in enumerate(S):
        if not cnt: continue
        if clappers < i:
            friends += i - clappers
            clappers = i
        clappers += cnt
    return friends

def main():
    files = []
    for fn in os.listdir('.'):
        if fn.endswith('.in'):
            files.append((os.path.getmtime(fn), fn))
    fn = max(files)[1]

    root = fn[:-2]
    with open(fn) as fd:
        global FD
        FD = fd
        backupstdout = sys.stdout
        sys.stdout = open(root+'out', 'wb')
        doit()
        sys.stdout = backupstdout
        subprocess.call(['diff', '-sdu', root+'good', root+'out'])

if __name__ == '__main__':
    main()
