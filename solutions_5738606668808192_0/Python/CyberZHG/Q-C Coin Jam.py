import random

small_primes = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31]
is_prime = [False, False] + [True] * (1 << 20)
primes = []

for i in xrange(2, len(is_prime)):
    if is_prime[i]:
        primes.append(i)
        for j in xrange(i + i, len(is_prime), i):
            is_prime[j] = False

def probably_prime(n, k):
    if n < 2: return False
    if n < len(is_prime):
        return is_prime[n]
    for p in small_primes:
        if n < p * p: return True
        if n % p == 0: return False
    r, s = 0, n - 1
    while s % 2 == 0:
        r += 1
        s //= 2
    for _ in range(k):
        a = random.randrange(2, n - 1)
        x = pow(a, s, n)
        if x == 1 or x == n - 1:
            continue
        for _ in range(r - 1):
            x = pow(x, 2, n)
            if x == n - 1:
                break
        else:
            return False
    return True

N, M = 16, 50
exist = []
with open('C-small-attempt0.out', 'w') as writer:
    writer.write('Case #1:\n')
    while len(exist) < M:
        s = '1'
        for _ in xrange(N - 2):
            if random.random() < 0.5:
                s += '0'
            else:
                s += '1'
        s += '1'
        if s in exist:
            continue
        flag = True
        factors = []
        nums = []
        for i in xrange(2, 11):
            num = int(s, i)
            nums.append(num)
            if probably_prime(num, 100):
                flag = False
                break
            flag = False
            for p in primes:
                if num % p == 0:
                    factors.append(p)
                    flag = True
                    break
            if not flag:
                break
        if flag:
            exist.append(s)
            writer.write(s)
            print s
            print nums
            print factors
            assert len(factors) == 9
            for f in factors:
                writer.write(' ' + str(f))
            writer.write('\n')
