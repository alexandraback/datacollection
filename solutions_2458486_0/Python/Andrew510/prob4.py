#!/usr/bin/python

import sys
infile = sys.stdin
#infile = open('in.txt', 'r')

allchests = []

class scenario(object):
    def __init__(self, keys, chests):
        self.keys = tuple(keys)
        self.chests = tuple(chests)

    def solve(self, failed):
        if (self.keys, self.chests) in failed:
            return None

        if len(self.chests) == 0:
            return []

        for c in self.chests:
            if allchests[c][0] not in self.keys:
                continue
        
            newkeys = list(self.keys)
            newkeys.remove(allchests[c][0])
            newkeys.extend(allchests[c][1])
            newkeys.sort()
            
            newchests = list(self.chests)
            newchests.remove(c)
            
            newscen = scenario(newkeys, newchests)
            result = newscen.solve(failed)
            if result is not None:
                result.append(c)
                return result
        
        failed.add((self.keys, self.chests))
        return None

        

T = int(infile.readline())
for t in range(T):
    K, N = map(int, infile.readline().split())

    keys = map(int, infile.readline().split())
    def readchest():
        L = map(int, infile.readline().split())
        return (L[0], L[2:])
    allchests = [ readchest() for _ in range(N) ]

    scen = scenario(keys, range(len(allchests)))
    failed = set()
    res = scen.solve(failed)

    if res is None:
        res = 'IMPOSSIBLE'
    else:
        res.reverse()
        res = ' '.join(['%d' % (n+1) for n in res ])

    print 'Case #%d: %s' % (t+1, res)
