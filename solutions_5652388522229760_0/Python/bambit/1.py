#!/usr/local/bin/python

import sys

def solve(t):
    N = int(sys.stdin.readline().rstrip())

    if N == 0:
        print 'Case #{}: {}'.format(t, 'INSOMNIA')
        return


    # 9 -> 100
    # 45 -> 1000
    ulimit = 10**(len(str(N))+1)
    
    digit_set = set(str(i) for i in range(10))
    num = N
    while num <= ulimit:
        for c in str(num):
            if c in digit_set:
                digit_set.remove(c)

        if not digit_set:
            break

        num += N

    print 'Case #{}: {}'.format(t, num)

if __name__=="__main__":
    T = int(sys.stdin.readline())
    for i in range(1, T+1):
        solve(i)
