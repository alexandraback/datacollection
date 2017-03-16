#!/usr/bin/env python3

def spojny(s):
    used = {}
    pop = ''
    fail = False
    for c in s:
        if c != pop:
            pop = c
            if c in used:
                fail = True
            else:
                used[c] = True
    return not fail

T = int(input())

for t in range(1, T+1):
    N = int(input())
    nextl = {}
    thisl = {}
    used = {}
    fail = False
    sc = input()
    for s in sc.split():
        if not spojny(s):
            fail = True

        pop = s[0]
        if pop not in used:
            used[pop] = True
        for c in s[1:]:
            if pop != c:
                if pop not in nextl:
                    nextl[pop] = c
                else:
                    fail = True
                pop = c
                if pop not in used:
                    used[pop] = True

        if s[0] == s[-1]:
            if s[0] not in thisl:
                thisl[s[0]] = 1
            else:
                thisl[s[0]] += 1

    res = {}
    def uzup(k):
        if k not in res:
            res[k] = k + nextl[k];
            if nextl[k] in nextl:
                res[k] += uzup(nextl[k])[1:]
            return res[k]
        else:
            return res[k]
    
    for k in nextl:
        uzup(k)
    
    res2 = dict(res)
    for x in res:
        for c in res[x][1:]:
            if c in res2:
                del res2[c]
    
    for k in used:
        add = True
        for x in res2.values():
            if k in x:
                add = False
        if add:
            res2[k] = k

    res3 = {}
    for s in res2.values():
        mnoz = 1
        for c in s:
            if c in thisl:
                mnoz *= thisl[c]
        res3[s] = mnoz

    def silnia(n, mod):
        if n < 2:
            return 1
        else:
            return (n * silnia(n-1, mod)) % mod
    def mnoz(di, mod):
        m = 1
        for k in di:
            m *= silnia(di[k], mod)
            m %= mod
        return m

    wynik = 0
    mod = 1000000007
    if not fail:
        wynik = (silnia(len(res3), mod) * mnoz(res3, mod)) % mod
    print("Case #{}: {}".format(t, wynik))
    
