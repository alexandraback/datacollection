#! /usr/bin/python
import os
import pyximport

#pyximport.install()
#os.chdir(os.path.dirname(os.path.abspath(__file__)))


#from ExtSolve import *

inf = open('input.in')
inp = inf.read().split('\n')
inf.close()

def Solve(*args):
    C, D, V, Coins = args
    new_coin = 0
    max_v = 0
    while max_v < V:
        aCoins = filter(lambda x:x <= max_v+1, Coins)
        if aCoins and sum(aCoins) * C > max_v:
            max_v = sum(aCoins) * C
        else:
            Coins += [max_v+1]
            new_coin += 1
    return new_coin

T = int(inp.pop(0))
outf = open('output','w')
for i in range(T):
    c, d, v = [int(x) for x in inp.pop(0).split(' ')]
    coins = [int(x) for x in inp.pop(0).split(' ')]
    outf.write('Case #%d: %s\n'%(i+1,Solve(c, d, v, coins)))
outf.close()