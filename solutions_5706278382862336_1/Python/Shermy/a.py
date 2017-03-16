#!/usr/bin/python3
from sys import argv

def gcd(p, q):
    r = 0
    while q != 0:
        r = p % q
        p = q
        q = r
    return p

with open(argv[1]) as inp, open(argv[2], 'w') as out:
    cases = int(inp.readline())
    for case in range(cases):
        p, q = (int(x) for x in inp.readline().split('/'))
        
        count = 0
        d = gcd(p, q)
        p = p // d
        q = q // d
        if (not (q == 0)) and (not (q & (q - 1))):
            while p < q:
                count += 1
                p *= 2

            if count <= 40:
                out.write("Case #%d: %d\n" % ((case + 1), count))
            else:
                out.write("Case #%d: impossible\n" % (case + 1))
        else:
            out.write("Case #%d: impossible\n" % (case + 1))
