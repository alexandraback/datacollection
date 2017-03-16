#!/usr/bin/python2.7
import sys

def to_bits(x):
    r = []
    while x > 0:
        r.append(x % 2)
        x /= 2
    if len(r) == 0:
        r.append(0)
    return r

if __name__ == "__main__":
    tcn = int(sys.stdin.readline())
    for tc in range(tcn):
        parts = sys.stdin.readline().split()
        a = int(parts[0])
        b = int(parts[1])
        k = int(parts[2])

        res = 0
        for i in range(a):
            for j in range(b):
                if (i & j) < k:
                    res += 1
        print "Case #" + str(tc + 1) + ":", res
