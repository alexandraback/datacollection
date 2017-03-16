#!/usr/bin/python3
import sys

def compress(s):
    s = s.rstrip('+')
    l = []
    for c in s:
        if len(l) > 0 and l[-1] == c:
            continue
        l.append(c)
    return ''.join(l)

def solve(niz):
    return len(compress(niz))

if __name__ == '__main__':
    t = int(sys.stdin.readline())
    for i in range(1, t+1):
        niz = sys.stdin.readline().strip()
        l = solve(niz)
        print('Case #{0}: {1}'.format(i, l))
