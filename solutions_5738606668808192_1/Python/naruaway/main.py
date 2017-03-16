import random
import math

def divisor(n):
    if n == 1:
        return 1
    if n == 2:
        return 1
    if n == 3:
        return 1
    for d in range(2, min(n, 100)):
        if n % d == 0:
            return d
    return 1

def build_number(r, base, n):
    num = 1 + base ** (n - 1)
    for i in range(1, n - 1):
        num += r[i - 1] * base ** i
    return num


def gen(N):
    while True:
        r = [random.randint(0, 1) for _ in range(N - 2)]
        divisors = [divisor(build_number(r, b, N)) for b in range(2, 11)]
        if any(d == 1 for d in divisors):
            continue
        return '1' + ''.join(str(i) for i in reversed(r)) + '1', divisors


def solve(N, J):
    answers = dict()
    while True:
        digits, divisors = gen(N)
        answers[digits] = divisors
        if len(answers) == J:
            break

    print('Case #1:')
    for digits, divisors in answers.items():
        print('{} {}'.format(digits, ' '.join(map(str, divisors))))

solve(32, 500)
