import sys
from sets import Set

def readInts():
    return map(int, sys.stdin.readline().strip().split())

def getPosition(name, n):
    vowels = 'aeiou'

    sz = len(name)
    consonant = 0
    s = 0

    l = []
    for i in xrange(sz):
        if name[i] in vowels:
            if consonant >= n:
                l.append((s, consonant))
            consonant = 0
        else:
            if consonant==0:
                s = i
            consonant += 1

    if consonant >= n:
        l.append((s,consonant))

    return l

def solve(name, n):
    sz = len(name)
    
    p = 0
    for i in xrange(sz):
        for j in xrange(i+n-1,sz):
            nn = name[i:j+1]

            l = getPosition(nn, n)
            if l:
                p += 1
            
            
    return p

T = readInts()[0]

for case in xrange(1,T+1):
    name, n = sys.stdin.readline().strip().split()
    n = int(n)

    print 'Case #%d: %d' % (case, solve(name, n))
