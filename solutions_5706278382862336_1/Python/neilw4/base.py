#!/usr/bin/python
import sys

def memo(f):
    cache = {}

    def memf(*x):
        if not x in cache:
            cache[x] = f(*x)
        return cache[x]
    return memf

    def memo(*x):
        if not x in cache:
            cache[x] = f(*x)
        return cache[x]
    return memf

def valid(p, q, g):
    return (p * (2**g)) % q == 0

def solve(l):
    l = l.split('/')
    p = int(l[0])
    q = int(l[1])
    g = 40
    if not valid(p, q, g):
        return "impossible"
    for i in xrange(0, g):
        if p * (2**i) >= q:
            return i



#needs an input file
infname = sys.argv[1]
inf = open(infname)
#assumes infname ends with .in
outfname = infname[:-3] + ".out"
#output file can be specified separately
if len(sys.argv) > 2:
    outfname = sys.argv[2]
outf = open(outfname, "w")
case = 1
#ignore 1st line
inf.readline()
while True:
    line = inf.readline()
    if line == '':
        break
    sol = "Case #" + str(case) + ": " + str(solve(line.strip()))
    print sol
    outf.write(sol + "\n")
    case += 1
