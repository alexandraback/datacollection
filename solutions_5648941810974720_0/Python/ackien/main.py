#!/usr/bin/python

from sys import stdin, stdout

T = int(stdin.readline().strip())

W = ['ZERO', 'ONE', 'TWO', 'THREE', 'FOUR', 'FIVE', 'SIX', 'SEVEN', 'EIGHT', 'NINE']
C = 'ZOWHUFXVGI'
scan_order = [0,2,4,6,8,1,3,5,7,9]


for case_num in range(1, T+1):
    S = list(stdin.readline().strip())
    counts = [0 for i in range(10)]
    for i in scan_order:
        if not len(S):
            break
        while C[i] in S:
            counts[i] += 1
            for c in W[i]:
                S.remove(c)
    answer = ''.join([str(i)*c for i,c in enumerate(counts)])
    stdout.write("Case #{:d}: {:s}\n".format(case_num, answer))
