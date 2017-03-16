#!/usr/bin/python

import sys

def read_obj(cls):
    return cls(sys.stdin.readline().strip())

def read_obj_list(cls):
    return map(cls, sys.stdin.readline().strip().split())

def fac(n):
    if n < 2:
        return 1
    return n * fac(n - 1)

def solve():
    t = read_obj(int)
    MOD = 10**9 + 7
    for i in xrange(1, t + 1):
        n = read_obj(int)
        tab = [[0, 0, 0, 0] for x in xrange(26)]
        neighs = [[-1, -1] for x in xrange(26)]
        res = 1
        gld = 0
        ss = read_obj_list(str)
        for s in ss:
            vis = [False for x in xrange(26)]
            last = ''
            for ch in s:
                num = ord(ch) - ord('a')
                if vis[num] and last != ch:
                    res = 0
                vis[num] = True
                last = ch
            for num in xrange(26):
                if vis[num]:
                    ch = chr(num + ord('a'))
                    if s[0] == ch == s[-1]:
                        tab[num][2] += 1
                    elif s[0] == ch:
                        tab[num][0] += 1
                        neighs[num][1] = ord(s[-1]) - ord('a')
                    elif s[-1] == ch:
                        tab[num][1] += 1
                        neighs[num][0] = ord(s[0]) - ord('a')
                    else:
                        tab[num][3] += 1
        for num in xrange(26):
            if any(tab[num]):
                ch = chr(num + ord('a'))
                if tab[num][3] != 0 and sum(tab[num]) > 1:
                    res = 0
                if tab[num][0] > 1 or tab[num][1] > 1:
                    res = 0
                res *= fac(tab[num][2])
                res %= MOD
                gld += (sum(tab[num]) - 1)
        vis = [False for x in xrange(26)]
        for num in xrange(26):
            if vis[num]:
                continue
            ch = chr(num + ord('a'))
            if tab[num][1]:
                vis[neighs[num][0]] = True
                k = num
                while neighs[k][1] != -1:
                    if vis[neighs[k][1]]:
                        res = 0
                        break
                    vis[neighs[k][1]] = True
                    k = neighs[k][1]
        res *= fac(n - gld)
        res %= MOD
        print "Case #%d: %d" % (i, res)

if __name__ == "__main__":
    solve()
