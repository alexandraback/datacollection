import doctest
import random
import sys


def is_prime(n, num_trial=None):
    """
        >>> is_prime(2357223335555577777772357)
        True
        >>> is_prime(2357223335555577777772359)
        False
    """
    if n == 2:
        return True
    if n < 2 or n & 1 == 0:
        return False

    if num_trial is None:
        num_trial = max(len(str(n)), 20)

    s, d = 1, (n - 1) >> 1
    while d & 1 == 0:
        s += 1
        d >>= 1

    for i in xrange(num_trial):
        a = random.randint(1, n - 1)
        if pow(a, d, n) != 1 and all(pow(a, d * (1 << r), n) != n - 1 for r in xrange(s)):
            return False
    return True

doctest.testmod()

T = int(raw_input())
assert T == 1
N, J = map(int, raw_input().split())

print 'Case #1:'

number_of_output = 0
for b in xrange(1 << (N - 2), 1 << (N - 1)):
    bits = ''.join([bin(b)[2:], '1'])
    ok = True
    for base in xrange(2, 10 + 1):
        n = int(bits, base)
        if is_prime(n, 1000):
            ok = False
            break
    if ok:
        output = [None] * 10
        output[0] = bits
        for base in xrange(2, 10 + 1):
            n = int(bits, base)
            m = 3
            while m < 10000:
                if n % m == 0:
                    output[base - 1] = m
                    break
                m += 2

        if all(output):
            print ' '.join(map(str, output))
            sys.stdout.flush()

            number_of_output += 1
            if number_of_output == J:
                break
