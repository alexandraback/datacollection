import pickle

import random

# def _gen_primes():
#     """ Generate an infinite sequence of prime numbers.
#     http://stackoverflow.com/questions/567222/simple-prime-generator-in-python
#     """
#     D = {}
#     q = 2
#
#     while True:
#         if q not in D:
#             yield q
#             D[q * q] = [q]
#         else:
#             for p in D[q]:
#                 D.setdefault(p + q, []).append(p)
#             del D[q]
#
#         q += 1
#
# PRIMES = []
# try:
#     for i, x in enumerate(_gen_primes()):
#         if i and i % 10000 == 0:
#             print(i)
#         PRIMES.append(x)
# finally:
#     with open("primes.pickle", "wb") as f:
#         pickle.dump(PRIMES, f)
#     print("Saving:", len(PRIMES))

# OUT = "coins.small.txt"
# N = 16
# J = 50

OUT = "coins.large.txt"
N = 32
J = 500

with open("primes.pickle", "rb") as f:
    PRIMES = pickle.load(f)


def get_random_binary(digits):
    return "1" + "".join(
        str(random.randint(0, 1)) for _ in range(digits - 2)) + "1"


def is_prime(x):
    stop_at = int(x ** 0.5 + 1)
    for i in PRIMES:
        if x % i == 0:
            return i
        if i > stop_at:
            return 0
    return 0


def get_candidate():
    global n, c
    while True:
        b1 = get_random_binary(N // 2)
        b2 = get_random_binary(N // 2)
        n = int(b1, 2) * int(b2, 2)
        c = bin(n)[2:]
        if len(c) == N:
            break
    return c, b1, b2


def check_candidate(c):
    proof = []
    for i in range(3, 11):
        x = int(c, i)
        ret = is_prime(x)
        if not ret:
            return False
        proof.append(ret)
    return proof



with open(OUT, "w") as f:
    coins = set()
    print("Case #1:", file=f)
    for i in range(J):
        if i and i % 10 == 0:
            print(i)
        while True:
            c, b1, b2 = get_candidate()
            if int(c, 2) in coins:
                print("hit", i)
                continue
            proof = check_candidate(c)
            if not proof:
                print("prime", i)
                continue

            break

        coins.add(int(c, 2))
        print(c, int(b1, 2), *proof, file=f)
print(len(coins))
print("Done")
