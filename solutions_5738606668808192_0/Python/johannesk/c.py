import itertools
import random

assert int(input())==1
N, J = map(int, input().split())

primes = [2,3,5,7,11,13,17,19]

def isPrime(n):
    for p in primes:
        if n%p==0:
            return False
    return True

def someDivisor(n):
    assert not isPrime(n)
    for p in primes:
        if n%p==0:
            return p
    assert False

print("Case #1:")
answers = set()
while len(answers) < J:
    jamcoin = [1] + [random.randint(0, 1) for _ in range(N-2)] + [1]
    def base(b): return sum(b**i for i, x in enumerate(reversed(jamcoin)) if x)
    if all(not isPrime(base(b)) for b in range(2, 11)):
        answers.add(tuple([''.join(map(str, jamcoin))] + [someDivisor(base(b)) for b in range(2, 11)]))
for a in answers:
    print(*a)
