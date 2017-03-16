#!/usr/bin/env python2

import os, sys

inputfile = 'i'
if len(sys.argv) > 1:
    inputfile = sys.argv[1]

f = open(inputfile, 'r')

T = int(f.readline()[:-1])

n = 0
m = 0
box = None
toy = None

def rec(i, ci, j, cj):
    #print i, ci, j, cj,
    if i >= n or j >= m:
        #print i, ci, j, cj, 0, -2, 'no'
        return 0
    if box[i+1] == toy[j+1]:
        ans = 0
        if box[i] - ci < toy[j] - cj:
            ans = rec(i+2, 0, j, cj + box[i] - ci) + box[i] - ci
        elif box[i] - ci > toy[j] - cj:
            ans = toy[j] - cj + rec(i, ci + toy[j] - cj, j+2, 0)
        else:
            ans = box[i] - ci + rec(i + 2, 0, j+ 2, 0)
        #print i, ci, j, cj, ans, -1, 'e'
        return ans
    ans = 0
    tp = j
    use = 0
    while tp < m and toy[tp+1] != box[i+1]:
        tp += 2
    if tp < m:
        tmp = 0
        if box[i] - ci > toy[tp]:
            tmp = toy[tp] + rec(i, ci + toy[tp], tp + 2, 0)
        elif box[i] - ci < toy[tp]:
            tmp = box[i] - ci + rec(i+2, 0, tp, box[i] - ci)
        else:
            tmp = toy[tp] + rec(i+2, 0, tp+2, 0)
        if tmp > ans: 
            ans = tmp
            use += 1
    tp = i
    while tp < n and box[tp+1] != toy[j+1]:
        tp += 2
    if tp < n:
        tmp = 0
        if toy[j] - cj > box[tp]:
            tmp = box[tp] + rec(tp + 2, 0, j, cj + box[tp])
        elif toy[j] - cj < box[tp]:
            tmp = toy[j] - cj + rec(tp, toy[j] - cj, j+2, 0)
        else:
            tmp = box[tp] + rec(tp+2, 0, j+2, 0)
        if tmp > ans: 
            ans = tmp
            use += 1
    tmp = rec(i+2, 0, j+2, 0)
    if tmp > ans:
        ans = tmp
    #print i, ci, j, cj, ans, use, 'com'
    return ans
    
for t in range(T):
    s = f.readline()[:-1]
    ary = s.split(' ')
    n = int(ary[0]) * 2
    m = int(ary[1]) * 2
    box = map(lambda _:int(_), f.readline()[:-1].split(' '))
    toy = map(lambda _:int(_), f.readline()[:-1].split(' '))
    print 'Case #%d:' % (t+1), rec(0, 0, 0, 0)

