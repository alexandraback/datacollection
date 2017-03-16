#!/usr/bin/env python3

import random

N = 32
J = 500

NN = 1<<N

output = []
used = {}

def convert_base(n_str):
    r = []
    for i in range(2, 11):
        r.append(int(n_str, i))
    return r

prime_list = []
def gen_prime_list(n):
    prime_list.append(2)
    for i in range(2,n>>1):
        ii = i*2-1
        prime = True
        for j in prime_list:
            if ii%j == 0:
                prime = False
                break
            if j*j > ii:
                break
        if prime:
            prime_list.append(ii)
    return prime_list

prime_list = gen_prime_list(1000000)
def is_prime_fast(n):
    for i in prime_list:
        if n == i:
            return None
        if n%i == 0:
            return i
    return None


def find_div(n):
    r = []
    for j in n:
        rr = is_prime_fast(j)
        if rr is None:
            return None
        r.append(rr)
    return r

while len(output) < J:
    n = random.randint(NN/4, NN/2 - 1)*2 + 1
    if n in used:
        continue
    used[n] = True
    n_str = format(n, 'b')
    s = convert_base(n_str)
    r = find_div(s)
    if r is not None:
        output.append((n_str,r))

print("Case #1:")
for o in output:
    print(o[0], end=" ")
    for j in o[1]:
        print(j, end=" ")
    print()
