#!/usr/bin/python3
import sys
from collections import deque

ans = dict()

def zamenjaj(s):
    return ''.join('+' if c == '-' else '-' for c in s)

def obrati(s):
    return [zamenjaj(s[:i])[::-1] + s[i:] for i in range(1, len(s)+1)]

def precompute():
    q = deque()
    for i in range(1, 10+1):
        ans['+' * i] = 0
        q.append('+' * i)
    while len(q) > 0:
        niz = q.popleft()
        l = obrati(niz)
        for s in l:
            if s in ans:
                continue
            ans[s] = ans[niz] + 1
            q.append(s)

def solve(niz):
    return ans[niz]

if __name__ == '__main__':
    precompute()
    t = int(sys.stdin.readline())
    for i in range(1, t+1):
        niz = sys.stdin.readline().strip()
        l = solve(niz)
        print('Case #{0}: {1}'.format(i, l))
