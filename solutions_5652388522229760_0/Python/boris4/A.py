#!/usr/bin/python
import sys

T = int(sys.stdin.readline().strip())

def update(curNum, seen):
    while curNum > 0:
        seen[curNum % 10] = True
        curNum /= 10

def isDone(seen):
    for x in seen:
        if x == False:
            return False
    return True

for testId in range(1, T + 1):
    sys.stdout.write('Case #%s: ' % testId)
    N = int(sys.stdin.readline().strip())

    if N == 0:
        print 'INSOMNIA'
    else:
        seen = [False] * 10
        curNum = N
        update(curNum, seen)
        while not isDone(seen):
            curNum += N
            update(curNum, seen)

        print curNum
