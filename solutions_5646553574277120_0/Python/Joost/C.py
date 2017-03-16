#! /usr/bin/env python

from itertools import combinations

fname = 'C-small-attempt1'

fin = open(fname+'.in', 'r')
fout = open(fname+'.out', 'w')

def canmakeall(coins, V):
    need = set(range(1, V+1))
    for L in range(1, len(coins)+1):
        for subcoins in combinations(coins, L):
            s = sum(subcoins)
            if s in need:
                need.remove(s)
    return not need

def solve(fin):
    C, D, V = list(map(int, fin.readline().split()))
    denoms = set(list(map(int, fin.readline().split())))
    leftcoins = set(range(1, V+1)) - denoms
    if C > 1 or D > 5 or V > 30:
        return "Not implemented"
    if canmakeall(denoms, V):
        return 0
    for L in range(1, 6):
        for newcoins in combinations(leftcoins, L):
            if canmakeall(set(newcoins) | denoms, V):
                return L

T = int(fin.readline())
for i in range(1, T+1):
    print(i)
    fout.write("Case #"+str(i)+": "+str(solve(fin))+"\n")
fout.close()
fin.close()
