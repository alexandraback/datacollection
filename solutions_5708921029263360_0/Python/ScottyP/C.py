#!/usr/local/bin/python2.7

import sys

def readint(): return int(raw_input())
def readarray(f): return map(f, raw_input().split())


_T = readint()
for _t in range(_T):

    J, P, S, K = readarray(int)

    JP_dict = {}
    JS_dict = {}
    PS_dict = {}

    tups = []

    tot = -1*J*P*S
    for i in range(J*P*S):
        tot += J*P*S + 1
        s = 1 + tot/(J*P)
        p = 1 + (tot - (s - 1)*(J*P))/P
        j = 1 + (tot - (s - 1)*(J*P) - (p-1)*P)
        jp = (j, p)
        js = (j, s)
        ps = (p, s)
        if jp in JP_dict:
            if JP_dict[jp] >= K:
                continue
        if js in JS_dict:
            if JS_dict[js] >= K:
                continue
        if ps in PS_dict:
            if PS_dict[ps] >= K:
                continue
        tups.append((j, p, s))
        if jp not in JP_dict:
            JP_dict[jp] = 0
        if js not in JS_dict:
            JS_dict[js] = 0
        if ps not in PS_dict:
            PS_dict[ps] = 0
        JP_dict[jp] += 1
        JS_dict[js] += 1
        PS_dict[ps] += 1


    print 'Case #%i:'%(_t+1), len(tups)
    for tup in tups:
        print(' '.join(map(str, list(tup))))
    sys.stdout.flush()
