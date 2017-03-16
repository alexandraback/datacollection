#coding:utf8
import math

def special(l, i):
    s = 0
    for x in l:
        if x > i:
            s += math.ceil(x/i) - 1
    return s


def solve():
    D = int(input())
    l = [int(x) for x in input().split(' ')]
    M = max(l)
    m = M

    for i in range(1, M):
        x = special(l, i)
        if x + i < m:
            m = x + i
    return m

if __name__ == '__main__':
    T = int(input())
    for i in range(T):
        result = solve()
        print("Case #{}: {}".format(i+1, result))
