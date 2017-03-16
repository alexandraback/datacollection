#!/usr/local/bin/python3
# Codejam ID 6224486

from GCJ import GCJ

def parse(infile):
    A, B = GCJ.readstrs(infile)
    N = int(A)+1
    audience = [int(ch) for ch in B]
    return N, audience

def solve(data):
    M, audience = data
    friends = 0
    standing = 0
    shyness = 0
    for x in audience:
        if standing < shyness:
            friends += shyness-standing
            standing += shyness-standing
        standing += x
        shyness += 1

    return friends

GCJ('A', solve, parse, None).run()

