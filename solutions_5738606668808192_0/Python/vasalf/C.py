#!/usr/bin/python3

from random import randint

def rabbin_miller_test(n, a):
    s = n - 1
    while (s & 1) == 0:
        s >>= 1
    tr = False
    k = pow(a, s, n)
    while s < n - 1:
        if k != 1 and k != n - 1:
            tr = True
        elif k == 1:
            if tr:
                return False
            tr = False
        else:
            tr = False
        k = (k * k) % n
        s <<= 1
    return k == 1


def is_probably_prime(n):
    if n == 2:
        return True
    for i in range(20):
        a = randint(2, n - 1)
        if not rabbin_miller_test(n, a):
            return False
    return True


def divisor(n):
    i = 2
    while i * i <= n:
        if n % i == 0:
            return i
        i += 1
    return -1

t = int(input())

n, j = map(int, input().split())

ans = []
while len(ans) < j:
    s = ["1"]
    while len(s) < n - 1:
        c = randint(0, 1)
        s.append(chr(ord('0') + c))
    s.append('1')
    s = "".join(s)
    f = True
    for i in range(2, 11):
        if is_probably_prime(int(s, i)):
            f = False
            break
    if f:
        ans.append(s)

print("Case #1:")
for s in ans:
    print(s, end=' ')
    for i in range(2, 11):
        print(divisor(int(s, i)), end=' ')
    print()


