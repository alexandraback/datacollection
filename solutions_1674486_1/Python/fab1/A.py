#!/usr/bin/python

import sys
sys.setrecursionlimit(2000000)
def parse(fname):
    r = []
    f = open(fname, "r")
    T = f.readline()
    N = -1
    i = 1
    rr = {}
    for line in f:
        if i <= N:
            l = map(int, line.split())[1:]
            if len(l) > 0:
                rr[i] = l
            i += 1
        else:
            r.append(rr)
            rr = {}
            N = -1

        if N == -1:
            N = int(line)
            i = 1
            continue
    r.append(rr)
    f.close()
    return r[1:]


visited = []
def traverse(case, node):
    global visited

    if case.has_key(node):
        for n in case[node]:
            if n in visited:
                return 1
            else:
                visited.append(n)
                if traverse(case, n):
                    return 1
    return 0

def solve(case):
    global visited
    for node in case.iterkeys():
        visited = []
        if traverse(case, node):
            return 1

    return 0

if __name__ == "__main__":
    if len(sys.argv) > 1:
        data = parse(sys.argv[1])
    else:
        data = parse("A-sample.in")

    i = 1
    for case in data:
        print "Case #" + str(i) + ":",
        if solve(case) == 1:
            print "Yes"
        else:
            print "No"
        i += 1
