#!/usr/bin/env python3
import sys

def findDivisor(n, limit = 20000):
    i = 2
    while True:
        if i*i > n: break
        if i > limit: break
        if (n % i) == 0: return i
        i += 1

def makeNum(arr, base):
    ret = 0
    p = 1
    for a in arr:
        ret += a * p
        p = p * base
    return ret

def binarize(n, bits):
    ret = []
    for i in range(bits):
        ret.insert(0, n % 2)
        n = n // 2
    return ret

readInt = lambda: int(sys.stdin.readline())
readInts = lambda: map(int, filter(str.strip, sys.stdin.readline().split(' ')))

def main():
    assert readInt() == 1
    (N,J) = readInts()
    jnums = 0 
    print("Case #1:")
    for i in range(2 ** (N-2)):
        tst = [1] + binarize(i,N-2) + [1]
        witnesses = []
        for base in range(2,11):
            d = findDivisor(makeNum(tst, base))
            if d is None:
                break
            witnesses.append(d)
        else:
            jnums += 1
            print(''.join(map(str,tst[::-1])), ' '.join(map(str, witnesses)))
        if jnums >= J:
            break

if __name__ == "__main__": 
    main()
