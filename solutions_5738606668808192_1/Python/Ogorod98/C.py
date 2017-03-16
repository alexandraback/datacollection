#!/usr/bin/python3

t = int(input())

def solve():
    n, j = map(int, input().split())
    l = (n // 2) - 2
    for i in range(j):
        x = bin(i + 2 ** l)[2:] + '1'
        print(x * 2, ' '.join([str(int(x, b)) for b in range(2, 11)]))


for i in range(t):
    print("Case #{}: ".format(i + 1))
    solve()
