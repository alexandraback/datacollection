import sys
from collections import deque

def d(*args):
    sys.stderr.write(', '.join(map(str, args)) + "\n")

def printf(*args):
    print ''.join(map(str, args))

def int_input():
    return map(int, raw_input().split(' '))

def float_input():
    return map(float, raw_input().split(' '))

def findHigher(l, f, start):
    length = len(l)
    if length == 2:
        return start if f < l[0] else start+1
    if length == 1:
        return 0
    length2 = length/2
    if l[length2] > f:
        return findHigher(l[:length2+1], f, start)
    else:
        return findHigher(l[length2:], f, start + length2)

def findLower(l, f, start):
    length = len(l)
    if length == 2:
        return start+1 if f > l[1] else start
    if length == 1:
        return 0
    length2 = length/2
    if l[length2] >= f:
        return findLower(l[:length2], f, start)
    else:
        return findLower(l[length2:], f, start + length2)

def playDWar(n, naomi, ken):
    naomi = deque(naomi)
    ken = deque(ken)
    score = 0
    for i in xrange(n):
        if naomi[0] > ken[0]:
            score += 1
            naomi.popleft()
            ken.popleft()
        else:
            naomi.popleft()
            ken.pop()
    return score

def playWar(n, naomi, ken):
    naomi.reverse()
    while n != 0 and naomi[n-1] < ken[n-1]:
        del ken[findHigher(ken, naomi.pop(), 0)]
        n -= 1
    return n

def solve(n, naomi, ken):
    naomi.sort()
    ken.sort()
    return " ".join(map(str, [playDWar(n, naomi[:], ken[:]), playWar(n, naomi[:], ken[:])]))

def read_input():
    return (int(raw_input()), float_input(), float_input())

if __name__ == '__main__':
    for i in xrange(int(raw_input())):
        printf("Case #", i+1, ": ", str(solve(*read_input())))
