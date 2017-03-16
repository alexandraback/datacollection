#!/usr/bin/env python

import itertools
import os.path as path
from collections import namedtuple, Counter
import pprint
from copy import deepcopy

cache = {}

def memoize(f):
    global cache
    def memf(*x):
        if x not in cache:
            cache[x] = f(*x)
        return cache[x]
    return memf

O = []
I = []

def read_testcase(f):
    _, N = map(int, f.readline().strip().split())
    keys = map(int, f.readline().strip().split())
    K = tuple(keys)
    O = []
    I = []
    for _ in xrange(N):
        tmp = map(int, f.readline().split())
        O.append(tmp[0])
        if len(tmp) > 2:
            I.append(tmp[2:])
        else:
            I.append([])
    return K, N, O, I

@memoize
def rec(rem_chests, hold_keys):
    if len(rem_chests) == 1:
        if O[rem_chests[0]] in hold_keys:
            return [rem_chests[0]]
        else:
            return None

    if len(hold_keys) == 0:
        return None

    ans = None

    for chest in rem_chests:
        for key in set(hold_keys):
            if O[chest] == key:
                crc = list(rem_chests)
                chk = list(hold_keys)
                crc.remove(chest)
                chk.remove(key)
                chk += I[chest]
                chk.sort()
                tmp = rec(tuple(crc), tuple(chk))
                if tmp is not None:
                    return [chest]+tmp
                    #ret_candidate += [[chest]+tmp]
    return ans

def solve(KNOI):
    global O
    global I
    K, N, O, I = KNOI
    print '--------------------------'
    print K
    print N
    print O
    print I

    need_keys = {}
    for o in O:
        need_keys[o] = need_keys.get(o, 0) + 1
    all_keys = {}
    for k in K:
        all_keys[k] = all_keys.get(k, 0) + 1
    for i in I:
        for k in i:
            all_keys[k] = all_keys.get(k, 0) + 1

    for k in need_keys.keys():
        if  k not in all_keys or need_keys[k] > all_keys[k]:
            return 'IMPOSSIBLE'

    print need_keys
    print all_keys

    global cache
    cache = {}
    ans = rec(tuple(range(N)), K)
    if ans is None:
        return 'IMPOSSIBLE'
    tmp = []
    for a in ans:
        tmp.append(str(a+1))
    return ' '.join(tmp)

if __name__ == '__main__':
    ans = []
    with open('D-small-attempt3.in') as f:
    #with open('D.txt') as f:
        T = int(f.readline())
        print 'T =',T
        for i in xrange(T):
            tmp = solve(read_testcase(f))
            ans.append(tmp)
            print tmp

    with open('ans.txt', 'w') as f:
        for i, a in enumerate(ans, start=1):
            #print a
            f.write('Case #%d: %s\n'%(i, a))

