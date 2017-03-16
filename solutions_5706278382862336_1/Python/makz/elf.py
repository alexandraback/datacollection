from fractions import gcd
from math import log, ceil

for t in range(input()):
    print "Case #%s:" % str(t + 1),
    p, q = map(int, raw_input().split("/"))
    p, q = p / gcd(p, q), q / gcd(q, p)
    if (q & (q - 1)) != 0:
        print "impossible"
        continue
    print int(ceil(-log(p / float(q), 2)))
