#!/usr/bin/env python
import sys

def flatten(xs):
    new = []
    for x in xs:
        if type(x) == int:
            new.append(x)
        else:
            new.extend(flatten(x))
    return new

def solve(N, classes):
    inherit = map(list, classes)
    for x in xrange(N):
        for y in classes[x]:
            inherit[x].append(inherit[y-1])
    inherit = map(flatten, inherit)
    for x in inherit:
        seen = set()
        for y in x:
            if y in seen:
                return "Yes"
            seen.add(y)
    return "No"

if __name__ == '__main__':
    with open(sys.argv[1], 'rU') as fin, open(sys.argv[2], 'w') as fout:
        T = int(fin.readline())
        for case in xrange(1, T+1):
            print "Case #{0}:".format(case),

            N = int(fin.readline())
            classes = [map(int, fin.readline().split())[1:] for i in xrange(N)]

            soln = solve(N, classes)
            print soln
            print >> fout, "Case #{0}: {1}".format(case, soln)
