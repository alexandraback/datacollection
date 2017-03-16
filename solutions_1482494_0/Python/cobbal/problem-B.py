#!/usr/bin/python

def isWin(l, g):
    return all(x == 2 for x in g)

class LoserException (Exception):
    pass

def step(l, g):
    stars = sum(g)
    for i in range(len(g)):
        if g[i] < 2 and l[i][1] <= stars:
            g[i] = 2
            return
    best = None, -1
    for i in range(len(g)):
        if g[i] == 0 and l[i][0] <= stars:
            if l[i][1] > best[1]:
                best = i, l[i][1]
    if best[0] is None:
        raise LoserException()

    g[best[0]] = 1

def solve(l):
    try:
        g = [0] * len(l)
        moves = 0
        while not isWin(l, g):
            moves += 1
            step(l, g)
        return moves
    except LoserException, e:
        return "Too Bad"

T = int(raw_input())
for i in range(T):
    N = int(raw_input())
    l = []
    for j in range(N):
        l.append(tuple(map(int, raw_input().split())))
    print "Case #%i: %s" % (i+1, solve(l))

