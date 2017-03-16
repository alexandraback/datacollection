#!/usr/bin/env python
import random
import itertools

def read():
    return map(int, raw_input().split())


def get((a, b, c), abc2cnt):
    return 0 if (a, b, c) not in abc2cnt else abc2cnt[(a, b, c)]


def add((a, b, c), abc2cnt):
    if (a, b, c) not in abc2cnt:
        abc2cnt[(a, b, c)] = 0
    abc2cnt[(a, b, c)] += 1
    
    
def work(cases, (A, B, C, limit)):
    abcList = [abc for abc in itertools.product(range(1, A + 1), \
                                                range(1, B + 1), \
                                                range(1, C + 1))]
    
    ansList = []
    
    for loop in range(1000):
        random.shuffle(abcList)
        
        abc2cnt = {}
        candiAnsList = []
        
        for abc in abcList:
            a, b, c = abc
            
            isOk = True
            if get((a, b, -1), abc2cnt) >= limit:
                isOk = False
            if get((a, -1, c), abc2cnt) >= limit:
                isOk = False
            if get((-1, b, c), abc2cnt) >= limit:
                isOk = False
    
            if isOk:
                add((a, b, -1), abc2cnt)
                add((a, -1, c), abc2cnt)
                add((-1, b, c), abc2cnt)
                candiAnsList.append((a, b, c))
            
        if len(ansList) < len(candiAnsList):
            ansList = candiAnsList

    
    print "Case #%d: %d" % (cases, len(ansList))
    for (a, b, c) in ansList:
        print a, b, c
    


if __name__ == "__main__":
    for i in range(int(raw_input())):
        work(i + 1, read())
