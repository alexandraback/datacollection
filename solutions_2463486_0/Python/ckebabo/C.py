import sys

def readInts():
    return map(int, sys.stdin.readline().strip().split())

palindormes = []

def isPalindrome(n):
    l = list(str(n))
    r = l[:]
    r.reverse()

    return l==r

def __init():
    global palindormes
    
    MAX = 10**7

    i = 1
    while i<=MAX:
        square = i*i
        if isPalindrome(i) and isPalindrome(square):
            palindormes.append(square)
        i += 1
    
def numberOfFairAndSquare(A,B):
    cnt = 0
    for n in palindormes:
        if n>B: break
        if n>=A:
            cnt += 1

    return cnt

__init()

T = readInts()[0]
for case in xrange(1, T+1):
    A,B = readInts()

    print "Case #%d: %d" % (case, numberOfFairAndSquare(A,B))
