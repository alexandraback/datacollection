#! /usr/bin/env python3

import sys, itertools

def genL(keyb,S):
    if S==0:
        yield ""
    else:
        for k in keyb:
            for g in genL(keyb,S-1):
                yield k+g

def Noccur(Str, target):
    N = 0
    i = 0
    while True:
        i = Str.find(target,i)
        if i==-1:
            return N
        i += 1
        N += 1

def solve(K, L, S, keyb, target):
    ks = set(keyb)
    ts = set(target)
    assert(len(target)==L)
    if ks|ts != ks:
        return 0
    if S<L:
        return 0
    tt = target + target
    for t in range(1,L+1):
        if tt[t:][:L] == target:
            oN = t
            break
    max_bananas = (S-L)//oN + 1
    NN = 0
    noc = 0
    for t in genL(keyb,S):
        NN += 1
        noc += Noccur(t,target)

    return max_bananas - noc/NN
    

number_of_test_cases = int(sys.stdin.readline())
for test_no in range(1, number_of_test_cases+1):
    K, L, S = map(int, sys.stdin.readline().split())
    keyb = sys.stdin.readline().split()[0]
    target = sys.stdin.readline().split()[0]
    print("Case #{}: {}".format(test_no,
                                solve(K, L, S, keyb, target)))
