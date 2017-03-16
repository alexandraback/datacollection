#!/usr/bin/python
#coding: utf-8

import os, sys
import math

def solve(input):
    def split(func, sep=' '):
        return map(func, input.readline().strip().split(sep))

    # small data
    s = split(int)[1:]
    N = len(s)
    result = {}
    def cal(n):
        sss = 0
        for j in range(N):
            if n & (1<<j):
                sss += s[j]
        return sss

    for i in range(1, 1<<N):
        tmp = cal(i)
        if result.has_key(tmp):
            break
        else:
            result[tmp] = i

    if i < (1 << N):
        tmp = result[cal(i)]
        return '\n%s\n%s' % (' '.join([str(s[j]) for j in range(N) if i & (1<<j)]), ' '.join([str(s[j]) for j in range(N) if tmp & (1<<j)]))
    else:
        return '\nImpossible'

    #result = {}
    #result2 = []
    #result1 = []
    #def dfs(i, sn):
    #    if i >= N:
    #        if result.has_key(sn):
    #            return True
    #        else:
    #            result[sn] = result1
    #            return False
    #    else:
    #        if dfs(i+1, sn):
    #            return True
    #        result1.append(s[i])
    #        flag = dfs(i+1, sn+s[i])
    #        if flag:
    #            result2.append(s[i])
    #            return True
    #        else:
    #            result1.pop()
    #            return False
    #if dfs(0, 0):
    #    return '\n%s\n%s' % (' '.join(map(str, result1)), ' '.join(map(str, result2)))
    #else:
    #    return '\nImpossible'


if __name__ == '__main__':
    with open(sys.argv[1], 'r') as input:
        T = int(input.readline().strip())
        for t in range(1, T+1):
            print 'Case #%d: %s' % (t, solve(input))
