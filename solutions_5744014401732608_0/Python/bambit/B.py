#!/usr/local/bin/python

import sys

def print_answer(case, slides, possible=True):
    if not possible:
        print 'Case #{}: IMPOSSIBLE'.format(case)
        return

    else:
        print 'Case #{}: POSSIBLE'.format(case)
        for row in slides:
            print ''.join(map(str, row))
        return

def get_in_binary(remaining_ways, k):
    if remaining_ways == (1 << (k-1)):
        return '1'*k

    b2 = (bin(remaining_ways)[2:])[::-1]

    pack = (k-1) - len(b2)
    b2 = '0'*pack + b2
    return '0' + b2

def solve(t):
    B, M = map(int, sys.stdin.readline().rstrip().split())

    # First find the first k such that 2**k < M and 2**(k+1) >= M
    k = 0
    cp = 1
    while cp < M:
        k += 1
        cp *= 2

    # cp is now at least M
    # k is the number of intermediary buildings we need
    if k > B-2:
        print_answer(t, None, False)
        return

    # Buildings 0 through k-1 are fully connected to each other, and to B
    slides = [[0 for i in range(B)] for j in range(B)]
    if k == 0:
        slides[0][B-1] = 1
        print_answer(t, slides)
        return

    for i in range(k):
        for j in range(i+1, k):
            slides[i][j] = 1
        slides[i][B-1] = 1

    slides[k][B-1] = 1
    remaining_ways = M - (1 << (k-1))


    ans = get_in_binary(remaining_ways, k)
    for i in range(k):
        slides[i][k] = ans[i]

    print_answer(t, slides)
    return

if __name__=="__main__":
    T = int(sys.stdin.readline())
    for i in range(1, T+1):
        solve(i)
