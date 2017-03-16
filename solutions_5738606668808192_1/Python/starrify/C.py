# coding: utf8

import random


def baseconv_yield(num, base):
    """Special purpose base converter"""
    assert 2 <= base <= 10
    while True:
        yield num % base
        num /= base
        if num == 0:
            return

def baseconv_10(num, base):
    """Convert num to base 10"""
    ret = 0
    for digit in num:
        ret *= base
        ret += int(digit)
    return ret


def get_divisor(primes, num, max_check):
    """Checks the first `max_check` primes for a divisor.
    Returns `None` if not found
    """
    for prime in primes[:max_check]:
        if num % prime == 0:
            return prime
    return None


def main():
    # Prime list obtained from https://primes.utm.edu/lists/small/millions/
    primes = []
    negative = set()
    num_prime_files = 23
    for i in range(num_prime_files):
        print(
            'Loading and preprocessing primes .. %s/%s done'
            % (i, num_prime_files)
        )
        with open('./primes/primes%s.txt' % (i + 1)) as f:
            # Skip two heading lines
            [f.readline() for x in range(2)]
            for line_no, line in enumerate(f):
                if line_no % 10000 == 0:
                    print('Processing line %s' % line_no)
                for prime_raw in line.split():
                    prime = int(prime_raw)
                    primes.append(prime)
                    for base in range(2, 11):
                        digits = []
                        skip = False
                        for digit in baseconv_yield(prime, base):
                            if not digit in (0, 1):
                                skip = True
                                break
                            digits.append(digit)
                        if not skip:
                            num = ''.join(str(x) for x in digits[::-1])
                            negative.add(num)
    for case, n, j in (
            ('sample', 6, 3),
            ('small', 16, 50),
            ('large', 32, 500),
            ):
        print('Processing case %s' % case)
        results = []
        used = set()
        while len(results) < j:
            tmp = random.randint(2 ** (n - 3), 2 ** (n - 2) - 1)
            if tmp in used:
                continue
            else:
                used.add(tmp)
            tmp = bin(tmp).split('b')[-1]
            tmp = '1%s1' % tmp
            if tmp not in negative:
                divisors = [
                    get_divisor(primes, baseconv_10(tmp, base), 10000)
                    for base in range(2, 11)
                ]
                if None not in divisors:
                    results.append([tmp] + divisors)

        with open('./C-%s.out' % case, 'w') as f:
            f.write('Case #1:\n')
            for result in results:
                f.write('%s\n' % (' '.join(str(x) for x in result)))


if __name__ == '__main__':
    main()
