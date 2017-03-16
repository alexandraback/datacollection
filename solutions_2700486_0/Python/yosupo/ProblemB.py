# -*- coding: utf-8 -*-
def num(n):
    return 2 * n * n - n

def calcnum(n):
    i = 1
    while num(i) <= n:
        i *= 2
    i //= 2
    j = i
    while j != 1:
        j //= 2
        if (num(i + j) < n):
            i += j
    return i, n - num(i)

cache = [1]
def calc(n, x, y):
    c, r = calcnum(n)
    p = 0
    l = (x + y) / 2 + 1
    if l <= c:
        return 1.0
    if l > c + 1:
        return 0.0
    if x == 0:
        return 0.0
    k = 2 * c
    t = y + 1
    if k + t <= r:
        return 1.0
    if r <= k:
        for i in range(t, r + 1):
            p += cache[r]//(cache[i] * cache[r - i])
        return p / 2**r
    else:
        if r - k >= t:
            return 1.0
        else:
            for i in range(t, r + 1):
                p += cache[r]//(cache[i] * cache[r - i])
            return p / 2**r
    return c, r

def kaizyo(n):
    return n * kaizyo(n - 1)
if __name__ == "__main__":
    s = open(input(), "r")
    count = int(s.readline())
    f=open("outputB.txt", "w")
    result = []
    k = 1
    for i in range(1, 3000):
        k *= i
        cache.append(k)
    for i in range(1, count+1):
        res = 0
        st = s.readline().split()
        n = int(st[0])
        x = abs(int(st[1]))
        y = int(st[2])
        result.append("Case #"+str(i)+": "+str(calc(n, x, y))+"\n")
    f.writelines(result)
    f.close()
