#! /usr/bin/python
# -*-coding:Utf-8 -*

def readint():    return int(raw_input())
def readarray(f): return map(f, raw_input().split())

def findSet(S, target):
    for i in range(len(S)):
        l = S[(i+1):]
        if S[i] < target:
            for r in findSet(l, target-S[i]):
                if r:
                    yield [S[i]] + r
        elif S[i] == target:
            yield [S[i]]
        else:
            break
    yield []

def allSubSets(S):
    if not S:
        yield []
    else:
        for s in allSubSets(S[1:]):
            yield s
            yield [S[0]]+s

T = readint()
for t in range(T):
    print 'Case #'+str(t+1)+':',

    input = readarray(int)
    N = input[0]
    num = sorted(input[1:])
    
    f = False
    for s in allSubSets(num):
        target = sum(s)
        for r in findSet(num, target):
            if r and r != s:
                print
                for i in r:
                    print i,
                print
                for i in s:
                    print i,
                print
                f = True
                break
        if f:
            break
    if not f:
        print 'Impossible'
