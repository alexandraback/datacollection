import sys


sys.setrecursionlimit = 100000


def rec(n, c):
    global ct
    if len(c) == n:
        if ct < m:
            print(1, end='')
            for i in range(n):
                print(c[i], end='')
            print(11, end='')
            for i in range(n):
                print(c[i], end='')
            print(1, end=' ')
            for i in range(2, 10):
                print((i ** (n + 2)) + 1, end=' ')
            print((10 ** (n + 2)) + 1)
        ct += 1
        return
    c.append(0)
    rec(n, c)
    c.pop()
    c.append(1)
    rec(n, c)
    c.pop()


t = int(input())
q, m = [int(i) for i in input().split()]
ct = 0
print('Case #1:')
rec((q // 2) - 2, [])