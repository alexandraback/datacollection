#!/usr/bin/python3

def solve():
    Sm, S = input().split()
    cnt = 0
    res = 0
    for i, x in enumerate(S):
        x = int(x)
        if x and i > cnt:
            res += i-cnt
            cnt += i-cnt
        cnt += x
    return res

if __name__ == "__main__":
    T = int(input())
    for t in range(T):
        print('Case #%d:' % (t+1), solve())
