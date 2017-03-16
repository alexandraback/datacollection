import numpy as np
import math

def parse(input_file, output_file):
    with open(input_file) as f:
        T = int(f.readline().split()[0])
        out = open(output_file, 'w')
        for i in range(T):
            N, J = map(int, f.readline().split())
            line = "Case #"+str(i+1)+":"
            print(line)
            out.write(line+'\n')

            sol = solve(N, J)
            # test(sol)
            for ans in sol:
                line = " ".join(map(str, ans))
                print(line)
                out.write(line+'\n')
    return

def primeSieve(sieveSize):
    # Returns a list of prime numbers calculated using
    # the Sieve of Eratosthenes algorithm.
    sieve = [True] * sieveSize
    sieve[0] = False # zero and one are not prime numbers
    sieve[1] = False
    # create the sieve
    for i in range(2, int(math.sqrt(sieveSize)) + 1):
        pointer = i * 2
        while pointer < sieveSize:
            sieve[pointer] = False
            pointer += i
    # compile the list of primes
    primes = []
    for i in range(sieveSize):
        if sieve[i] == True:
            primes.append(i)
    return primes

def solve(N, J):
    divi_max = 10000
    primeL = primeSieve(divi_max)
    sol = []
    for candidate in range(2**(N-1)+1, 2**N, 2):
        if len(sol) == J:
            return sol

        candi_bin = bin(candidate)[2:]
        ans = [candi_bin]
        for base in range(2, 11):
            candi_based = in_base(candi_bin, base)
            divisor = is_pseudo_prime(candi_based, primeL)
            if divisor:
                ans.append(divisor)
                continue
            else:  # no divisor, consider this prime
                break
        else:  # no break = all composite
            assert len(ans) == 10
            sol.append(ans)


def is_pseudo_prime(candi_based, primeL):
    for prime in primeL:
        if candi_based % prime == 0:
            return prime  # candidate has a divisor
    return 0
            


def in_base(coin, base):
    res = 0
    for ind, bit in enumerate(str(coin)):
        if ind != 0:
            res *= base
        res += int(bit)
    return res

def test(sol):
    for ans in sol:
        candi_bin = ans[0]
        for base in range(2, 11):
            divi = ans[base-1]
            if in_base(candi_bin, base) % divi != 0:
                raise ValueError('fjfjfjf')
            else:
                print(in_base(candi_bin, base), divi)



dir = "./"

input_file = dir+"C-test.in"
output_file = dir+"C-test.txt"

input_file = dir+"C-small-attempt0.in"
output_file = dir+"C-small-attempt0.txt"

input_file = dir+"C-large.in"
output_file = dir+"C-large.txt"

'''
'''
parse(input_file, output_file)
