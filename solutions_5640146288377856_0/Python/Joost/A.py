#! /usr/bin/env python

fname = 'A-small-attempt0'

fin = open(fname+'.in', 'r')
fout = open(fname+'.out', 'w')


def solve(fin):
    R, C, W = list(map(int, fin.readline().split()))
    deduct = 1 if C % W == 0 else 0
    return R*(C//W) + W - deduct

T = int(fin.readline())
for i in range(1, T+1):
    print(i)
    fout.write("Case #"+str(i)+": "+str(solve(fin))+"\n")
fout.close()
fin.close()
