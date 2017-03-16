#!/usr/bin/python3

input()
N, J = map(int, input().split())

primes = []
for i in range(3, 1000000, 2):
    fail = False
    for p in primes:
        if i % p == 0:
            fail = True
            break
        if p * p > i:
            break
    if not fail:
        primes.append(i)
primes.insert(0, 2)

count = 0
num = 2 ** (N - 1) + 1

print('Case #1:')
while count < J:
    s = bin(num)[2:]
    out = []
    for base in range(2, 11):
        v = int(s, base)
        for p in primes:
            if v <= p:
                break
            if v % p == 0:
                out.append(p)
                break
        if len(out) < base - 1:
            break
    if len(out) == 9:
        print(s, ' '.join(map(str, out)))
        count += 1
    num += 2
