#! /usr/bin/env python

fname = 'A-large'

fin = open(fname+'.in', 'r')
fout = open(fname+'.out', 'w')


def solve(fin):
    R, C, W = list(map(int, fin.readline().split()))
    return R*(C//W) + W - 1 * (C % W == 0)

T = int(fin.readline())
for i in range(1, T+1):
    print(i)
    fout.write("Case #"+str(i)+": "+str(solve(fin))+"\n")
fout.close()
fin.close()
