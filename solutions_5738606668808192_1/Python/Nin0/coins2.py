#!/usr/bin/python3

N = 32
J = 500

def divisor(n):
    if n <= 2:
        return None
    if n % 2 == 0:
        return 2
    i = 3
    while i*i <= n:
        if i > 1000000:
            return None  # We just discard the long-proof jamcoins.
        if n % i == 0:
            return i
        i += 2
    return None

def is_jamcoin(s):
    interpr = [int(s, i) for i in range(2, 10+1)]
    proof = []
    for x in interpr:
        d = divisor(x)
        if d is None:  # It's a prime!!
            return None
        proof.append(d)
    return proof

def add_zeros(s, n):
    return '0' * (n - len(s)) + s

print('Case #1:')
for i in range(0, 2**(N-2)):
    cand = '1' + add_zeros(bin(i)[2:], N-2) + '1'
    jc = is_jamcoin(cand)
    if jc:
        J -= 1
        print(cand, ' '.join(str(x) for x in jc))
    if J == 0:
        break