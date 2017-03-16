"""
A jamcoin is a string of N >= 2 digits with the following properties:

- Every digit is either 0 or 1.
- The first digit is 1 and the last digit is 1.
- If you interpret the string in any base between 2 and 10, inclusive, the
  resulting number is not prime.

Number will always be (b^(N-1) + 1 + sum(a[i] * b^i for i in xrange(1, N-1)))
where a[i] is 0 or 1.

2^(N-2) possibilities to check:
    - N=16: 16384
    - N=32: 1073741824

Time to check each one for primality in each base is O(sqrt(M)), where M is
bounded by b^N. Worst case is sqrt(10^N), or 10^(N/2). 10^8 is still a pretty
big bound, though doable... Definitely doesn't work for N=32.

Overall brute force would be, very roughly:

O(2^(N-2) * 10 ^ (N/2)) ~= 1,638,400,000,000

Not really workable...

Though each check for primality in lower bases can be done faster and act as
a filter to avoid doing as much work for higher bases. Even so,

O(2^(N-2) * 2 ^ (N/2)) ~= 4,194,304

But we don't need to figure out ALL of them, we just need to figure out J (50
for small, 500 for large) of them. Can we construct them procedurally somehow?

I wonder if we can leverage divisibility rules?

In base 10, what kinds of number could possibly be factors of numbers like:

    101011101


Or perhaps we can do a probabilistic primality test on every possible number
1xxxx1 in all bases and then only look for factors among those that fail. This
will occasionally claim that a number is prime when it's not, but that's okay
because we don't need find ALL jamcoins.
"""

import random
import math

_mrpt_num_trials = 5 # number of bases to test

def is_probable_prime(n):
    """From
    https://rosettacode.org/wiki/Miller%E2%80%93Rabin_primality_test#Python
    """
    assert n >= 2
    # special case 2
    if n == 2:
        return True
    # ensure n is odd
    if n % 2 == 0:
        return False
    # write n-1 as 2**s * d
    # repeatedly try to divide n-1 by 2
    s = 0
    d = n-1
    while True:
        quotient, remainder = divmod(d, 2)
        if remainder == 1:
            break
        s += 1
        d = quotient
    assert(2**s * d == n-1)
 
    # test the base a to see whether it is a witness for the compositeness of n
    def try_composite(a):
        if pow(a, d, n) == 1:
            return False
        for i in range(s):
            if pow(a, 2**i * d, n) == n-1:
                return False
        return True # n is definitely composite
 
    for i in range(_mrpt_num_trials):
        a = random.randrange(2, n)
        if try_composite(a):
            return False
 
    return True # no base tested showed n as composite

def all_candidate_jamcoins(N):
    for i in xrange(2 ** (N - 2)):
        yield '1%s1' % bin(i)[len('0b'):].zfill(N-2)

T = input()  # ignored
N, J = map(int, raw_input().split())

print 'Case #1:'

found = 0
for candidate in all_candidate_jamcoins(N):
    for base in xrange(2, 11):
        num = int(candidate, base)
        if is_probable_prime(num):
            break
    else:
        divs = []
        for base in xrange(2, 11):
            num = int(candidate, base)
            # Because we're not interested in finding ALL jamcoins, we can set
            # an arbitrary limit to avoid looking too hard for really large
            # factors
            stop_point = min(10 ** 6, int(math.sqrt(num) + 1))
            for div in xrange(3, stop_point, 2):
                if num % div == 0:
                    divs.append(div)
                    break
            else:
                break

        if len(divs) != 9:
            continue

        print ' '.join(map(str, [candidate] + divs))

        found += 1
        if found == J:
            break
