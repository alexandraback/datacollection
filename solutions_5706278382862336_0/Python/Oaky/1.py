#include <cstdio>

def getInput():
    return raw_input()

def getInt():
    return int(getInput())

def gcd(a, b):
    return a if (b == 0) else gcd(b, a % b)

def solve():
    a, b = getInput().split('/')
    a, b = int(a), int(b)
    while(True):
        val = gcd(a, b)
        if val == 1: break
        a /= val
        b /= val

    bb = b
    cnt = 0
    while bb > 1:
        if bb % 2 == 0:
            bb = bb / 2
        else:
            return "impossible"

    while b > 1:
        b /= 2
        cnt += 1
        if a >= b:
            return cnt

def main():
    alltest = getInt()
    for i in xrange(1, alltest + 1):
        print "Case #{}: {}".format(i, solve())

main()
