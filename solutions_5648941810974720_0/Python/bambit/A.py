#!/usr/local/bin/python

import sys

def clean(lmap, s, num):
    for c in s:
        lmap[c] -= num

def solve(t):
    l = sys.stdin.readline().rstrip()
    lmap = {}
    for c in l:
        lmap[c] = lmap.get(c, 0) + 1

    fin_num = ''

    for chrs, cleans, fin in [('Z', 'ZERO', '0'), 
            ('W', 'TWO', '2'), 
            ('U', 'FOUR', '4'), 
            ('X', 'SIX', '6'), 
            ('G', 'EIGHT', '8'), 
            ('F', 'FIVE', '5'), 
            ('O', 'ONE', '1'), 
            ('S', 'SEVEN', '7'), 
            ('T', 'THREE', '3'), 
            ('I', 'NINE', '9')]:
        if lmap.get(chrs, 0) > 0:
            num = lmap[chrs]
            fin_num += fin*num
            clean(lmap, cleans, num)
    print 'Case #{}: {}'.format(t, ''.join(sorted(fin_num)))

if __name__=="__main__":
    T = int(sys.stdin.readline())
    for i in range(1, T+1):
        solve(i)
