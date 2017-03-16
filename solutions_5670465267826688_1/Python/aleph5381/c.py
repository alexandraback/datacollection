#!/usr/bin/env python3

import sys
rl = lambda: sys.stdin.readline()
T = int(rl())

def mult(x, y):
    if x == '1':
        return y
    elif y == '1':
        return x
    elif x[0] == '-' and y[0] == '-':
        return mult(x[1], y[1])
    elif x[0] == '-':
        r = mult(x[1], y)
        if r[0] == '-':
            return r[1]
        else:
            return '-' + r
    elif y[0] == '-':
        r = mult(x, y[1])
        if r[0] == '-':
            return r[1]
        else:
            return '-' + r
    elif x == 'i':
        if y == 'i':
            return '-1'
        elif y == 'j':
            return 'k'
        elif y == 'k':
            return '-j'
    elif x == 'j':
        if y == 'i':
            return '-k'
        elif y == 'j':
            return '-1'
        elif y == 'k':
            return 'i'
    elif x == 'k':
        if y == 'i':
            return 'j'
        elif y == 'j':
            return '-i'
        elif y == 'k':
            return '-1'

def shorten(mystr):
    c = '1'
    for i in range(0, len(mystr)):
        c = mult(c, mystr[i])
    return c

def power(x, n):
    if n == 0:
        return '1'
    if n == 1:
        return x
    u = power(x, n//2)
    r = mult(u, u)
    if n%2 != 0:
        r = mult(r, x)
    return r

# they are associative, greedy split is ok
def solve(casei):
    line = rl().split()
    L = int(line[0])
    X = int(line[1])
    mystr = rl().strip()
    c = '1'
    matched = ''
    loop_wo_gain = 0
    for i in range(0, X):
        #print("DEBUG: ", i, "-th it: matched: ", matched)
        if matched == 'k':
            s = shorten(mystr)
            s = power(s, (X-i))
            c = mult(c, s)
            break
        if loop_wo_gain > 4:
            break
        loop_wo_gain += 1
        for j in range(0, L):
            nextc = mystr[j]
            nc = mult(c, nextc)
            #print("DEBUG:", c, "*", nextc, "=", nc)
            c = nc
            if matched == '' and c == 'i':
                matched = 'i'
                c = '1'
                loop_wo_gain = 0
            elif matched == 'i' and c == 'j':
                matched = 'j'
                c = '1'
                loop_wo_gain = 0
            elif matched == 'j' and c == 'k':
                matched = 'k'
                c = '1'
                loop_wo_gain = 0
    ans = ""
    #print("DEBUG: matched:", matched, ", c:", c)
    if matched == 'k' and c == '1':
        ans = "YES"
    else:
        ans = "NO"
    print("Case #{}: {}".format(casei, ans))

for i in range(1, T+1):
    solve(i)
