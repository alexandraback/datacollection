#!/usr/bin/python3
import sys

def solve(niz):
    if niz == '':
        return ''
    m, p = niz[0], 0
    for i in range(1, len(niz)):
        if niz[i] > m:
            m, p = niz[i], i
    s2 = solve(niz[:p])
    for c in niz[p:]:
        if c == m:
            s2 = c + s2
        else:
            s2 += c
    return s2

if __name__ == '__main__':
    t = int(sys.stdin.readline())
    for i in range(1, t+1):
        S = sys.stdin.readline().strip()
        last = solve(S)
        print('Case #{0}: {1}'.format(i, last))
