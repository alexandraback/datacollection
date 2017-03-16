#! /usr/bin/python

__author__ = 'Thomas "noio" van den Berg'

### IMPORTS ###
import sys
import numpy as np
import scipy.ndimage as ndi
from pprint import pprint

VOW = list("aeiou")
CONS = list("bcdfghjklmnpqrstvwxyz")

### FUNCTIONS ###

def do(tribes):
    mn = min(min(w*2, w*2 + dp * n * 2) for [d, n, w, e, s, dd, dp, ds] in tribes)
    mx = max(max(e*2, e*2 + dp * n * 2) for [d, n, w, e, s, dd, dp, ds] in tribes)
    
    wall = np.zeros((mx-mn))
    success = 0

    # print "\n\n\nCASE"
    # print mn

    while tribes:
        tribes = sorted(tribes)
        today = tribes[0][0]

        attacktoday = []
        while tribes and tribes[0][0] == today:
            attacktoday.append(tribes.pop(0))

        # print attacktoday

        newwall = wall.copy()
        
        # print "DAY =", today

        for [d, n, w, e, s, dd, dp, ds] in attacktoday:
            # print w, e
            l, r = (w*2 - mn), (e*2 - mn) + 1
            if any(wall[l:r] < s):
                success += 1
            # print l, r
            # print "SECTION: ", wall[l:r]
            # print 'strenght =', s
            newwall[l:r] = np.maximum(newwall[l:r], s)

            if n > 1:
                newtribe = [d + dd, n - 1, w + dp, e + dp, s + ds, dd, dp, ds]
                tribes.append(newtribe)

        wall = newwall
        # print newwall

    return success



### PROCESS INPUT FILE ###

if __name__ == '__main__':
    f = open(sys.argv[1])
    fout = open(sys.argv[1].replace('.in','.out'),'w')

    T = int(f.readline())
    for case in xrange(T):
        N = int(f.readline())
        tribes = []
        for _ in xrange(N):
            [d, n, w, e, s, dd, dp, ds] = [int(_) for _ in f.readline().split()]
            tribes.append([d, n, w, e, s, dd, dp, ds])

        ans = do(tribes)
        print ans
        fout.write('Case #%d: %s\n'%(case+1,ans))
