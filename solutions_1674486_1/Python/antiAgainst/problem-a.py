#!/usr/bin/python2

import sys
sys.setrecursionlimit(10000)

def findDiamond(classes, visited, c):
    if c in visited:
        return True
    visited.add(c)
    for next in classes[c]:
        result = findDiamond(classes, visited, next)
        if result:
            return True
    return False

if __name__ == "__main__":

    f = open('A-large.in')
    tc = int(f.readline().strip())

    for t in range(tc):
        print "Case #%d:" % (t + 1),

        n = int(f.readline().strip())
        classes = {}
        degree = {}
        degree0 = []
        for i in range(1, n+1):
            degree[i] = 0

        for c in range(1, n+1):
            rest = f.readline().split()
            father = rest[1:]
            father = [int(p) for p in father]
            for i in father:
                degree[i] += 1
            classes[c] = set(father)
        for c in range(1, n+1):
            if degree[c] == 0:
                degree0.append(c)
        result = False
        for c in degree0:
            if findDiamond(classes, set(), c):
                result = True
                break
        if result:
            print "Yes"
        else:
            print "No"


