#! /usr/bin/env python

from itertools import product

fname = 'B-small-attempt1'

fin = open(fname+'.in', 'r')
fout = open(fname+'.out', 'w')


def occurrences(string, sub):
    count = start = 0
    while True:
        start = string.find(sub, start) + 1
        if start > 0:
            count+=1
        else:
            return count


def solve(fin):
    K, L, S = list(map(int, fin.readline().split()))
    K = fin.readline().strip()
    L = fin.readline().strip()
    words = list(product(*[K] * S))
    worst = 0
    total = 0
    for word in words:
        c = occurrences(''.join(word), L)
        if c > worst:
            worst = c
        total += c
    avg = total / len(words)
    return worst - avg

T = int(fin.readline())
for i in range(1, T+1):
    print(i)
    fout.write("Case #"+str(i)+": "+str(solve(fin))+"\n")
fout.close()
fin.close()
