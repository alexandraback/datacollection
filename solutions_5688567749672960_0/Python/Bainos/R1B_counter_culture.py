#!/usr/bin/python
# -*- coding:Utf-8 -*-

n = int(input())
output = list()

l = [1, 1]

def solve(c) :
    if len(l) < c :
        build(c)
    try :
        return l[c]
    except :
        print("Error on %d" % c)

def build(c) :
    global l
    for i in range(len(l), c+2) :
        r = reverse(i)
        if r >= i or i % 10 == 0 :
            l.append(l[i-1] + 1)
        else :
            l.append(min(l[i-1], l[r])+1)

def reverse(i) :
    out = ""
    for c in str(i) :
        out = c + out
    return int(out)

for i in range(n) :
    case = int(input())
    output.append("Case #%d: %d" % (i+1, solve(case)))
print("\n".join(output))

