#!/usr/bin/env python
# -*- coding: utf-8 -*-
import re
import sys
import os
import time
import itertools
import collections

#R,C,M,MM=11,11,10*10+1,16
#
#
#dp = [ [ [ [0 for r in range(MM)]
#           for c in range(M)]
#         for mine in range(C)]
#         for mask in range(R)]

def f(r, c, m, mask):
    if m>=r*c:
        return -1

    ll,uu,rr,dd = [[0,1][(mask & _)>0] for _ in [1, 2, 4, 8]]
    print "ffff ", r,c,m,mask, ll,uu,rr,dd


    if dp[r][c][m][mask] == 0:
        dp[r][c][m][mask] = -1

        if m==0:
            if r*c==1:
                dp[r][c][m][mask] = ['c']
                return dp[r][c][m][mask]
            elif r==1:
                if not uu and not dd and c-ll-rr>0:
                    dp[r][c][m][mask] = [''.join(['.c'[_ == ll] for _ in range(c)])]
                    return dp[r][c][m][mask]
                else:
                    dp[r][c][m][mask] = -1
                    return -1
            elif c==1:
                if r - uu - dd >0 and not ll and not rr:
                    dp[r][c][m][mask] = ['.c'[_ == uu] for _ in range(r)]
                    return dp[r][c][m][mask]
                else:
                    dp[r][c][m][mask] = -1
                    return -1

            elif r - uu - dd >0 and c-ll-rr>0:
                dp[r][c][m][mask] = ['.' * c for _ in range(r)]
                dp[r][c][m][mask][uu] = ''.join(''.join(['.c'[_ == ll] for _ in range(c)]))
               #print "Got c"
                return dp[r][c][m][mask]
            else:
                dp[r][c][m][mask] = -1
                return -1

        #whole row
        if m >= c:
            #up
            xx = f(r-1, c, m - c, mask | 2)
            if xx!=-1:
                dp[r][c][m][mask] = [''.join(['*' for _ in range(c)])] + xx
                return dp[r][c][m][mask]
            #down
            xx = f(r-1, c, m - c, mask | 8)
            if xx!=-1:
                dp[r][c][m][mask] = [''.join(['*' for _ in range(c)])] + xx
                return dp[r][c][m][mask]
        else:
            #first row
            if 0 and r == 1:
                if not uu and not dd and c-m-1-rr >0:
                    dp[r][c][m][mask] = ['*' * m + '.c' +  '.' * (c-m-2)]
                   #print "Got c"

                    return dp[r][c][m][mask]
            else:
                if r - 2 - dd >0 and c-m-rr >0:
                    dp[r][c][m][mask] = ['*' * m + '.' * (c-m)] + ['.' * c for _ in range(r-1)]
                    dp[r][c][m][mask][2]=''.join(['.c'[_ == m] for _ in range(c)])
                   #print "Got c"

                    return dp[r][c][m][mask]

        if m >= r :
            #left
            xx = f(r, c-1, m - r, mask | 1)
            if xx!=-1:
                dp[r][c][m][mask] = ['*' + _ for _ in xx]
                return dp[r][c][m][mask]

            #right
            xx = f(r, c-1, m - r, mask | 4)
            if xx!=-1:
                dp[r][c][m][mask] = [_ + '*' for _ in xx]
                return dp[r][c][m][mask]
        else:
            #first column
            if 0 and c==1:
                if not ll and not rr and r - m -1 -dd>0:
                    dp[r][c][m][mask] = [['*'] for _ in range(m)] + ['.','c'] + ['.' for _ in range(r -m - 2)]
                   #print "Got c"

                    return dp[r][c][m][mask]
            else:
                if c - 1 -rr >0 and r -m -1 - dd > 0:
                    tt = [['.'] * c  for _ in range(r)]
                    for _ in range(m):
                        tt[_][0]='*'
                    tt[m+1][1] = 'c'
                    dp[r][c][m][mask] = [''.join(yy) for yy in tt]
                   #print "Got c"

                    return dp[r][c][m][mask]

    return dp[r][c][m][mask]

def main():
    n = int(raw_input())
    for nn in range(n):
        r,c,m = map(int, raw_input().strip().split())

        #print r,c,m
        ans = -1

        if m==0:
            ans = [['.' for _ in range(c)] for __ in range(r)]
            ans[0][0] = 'c'

        elif m==r*c-1:
            ans = [['*' for _ in range(c)] for __ in range(r)]
            ans[0][0] = 'c'

        elif r==1:
            if m <= c - 2:
                ans = [['*' for _ in range(m)] + ['.' for _ in range(c-1-m)] + ['c']]
        elif c==1:
            if m <= r - 2:
                ans = [['*'] for _ in range(m)] + [['.'] for _ in range(r-1-m)] + [['c']]
        else:
            if m <= r*c - 4:
                ans = [['*' for _ in range(c)] for __ in range(r)]
                x = r*c - m

                if (r-2) * c < m:
                    u = m - (r-2)*c
                    if u%2:
                        ans = -1
                    else:
                        for i in range(c-u/2):
                            ans[0][i] = '.'
                            ans[1][i]='.'
                        x-=2*c-u
                else:
                    for i in range(c):
                        ans[0][i]='.'
                        ans[1][i]='.'
                    x-=2*c

                if ans!=-1:
                    ans[0][0] = 'c'

                    for i in range(2, r):
                        if not x:
                            break
                        for j in range(c):
                            if i<2 and j<2:
                                continue
                            if not x:
                                break
                            x-=1
                            ans[i][j] = '.'


        if ans == -1:
            print "Case #%d:\nImpossible" % (nn+1)#, (r, c, m, r*c-m))
        else:
            print "Case #%d:\n%s" % (nn+1, '\n'.join(''.join(_) for _ in ans))



if __name__ == '__main__':
    main()
