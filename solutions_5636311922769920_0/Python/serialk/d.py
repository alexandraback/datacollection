#!/usr/bin/python3

def answer(k, c, s):
    return ' '.join([str(1 + (k ** (c - 1)) * i) for i in range(s)])


T = int(input())
for i in range(T):
    k, c, s = list(map(int, input().split()))
    print('Case #{}: {}'.format(i + 1, answer(k, c, s)))
