
import random

# so for the small case N = 16, so in base-2 the numbers run from 32769 to 65536


def do_sieve(size):
    is_prime = [1] * (size + 1)
    is_prime[0] = 0
    is_prime[1] = 0
    i = 2
    while i < int(size ** 0.5) + 1:
        j = i * 2
        while j <= size:
            is_prime[j] = 0
            j += i
        next_i = i + 1
        while is_prime[next_i] == 0:
            next_i += 1
        i = next_i
    with open('primes_to_{}.txt'.format(size), 'w') as file_out:
        for i in range(size):
            if is_prime[i]:
                file_out.write('{}\n'.format(i))


def primes_from_file(filename):
    with open(filename, 'r') as file_in:
        lines = file_in.readlines()[:-1]
    primes = [int(line) for line in lines]
    return primes


def main():
    with open('C-small-attempt1.in', 'r') as file_in, open('C.out', 'w') as file_out:
        lines = file_in.readlines()
        n, j = map(int, lines[1].split())
        coins = make_coins(n, j)

        file_out.write('Case #1:')
        for coin in coins:
            proof = coins[coin]
            file_out.write('\n{} {}'.format(coin, ' '.join(str(p) for p in proof)))
        print(len(coins))


def make_coins(n, j):
    primes = primes_from_file('primes_to_100000000.txt')
    coins = {}
    while len(coins) < j:
        trial_coin = '1' + ''.join([random.choice('01') for _ in range(n - 2)]) + '1'
        if trial_coin not in coins:
            print('try {}'.format(trial_coin))
            bad_coin = False
            proof = []
            for base in range(2, 11):
                coin_in_base = int(trial_coin, base)
                sqrt = int(coin_in_base ** 0.5) + 1
                if not miller_rabin(coin_in_base):
                    trial_prime_index = 0
                    found_divisor = False
                    while primes[trial_prime_index] < sqrt and not found_divisor and trial_prime_index < len(primes):
                        if coin_in_base % primes[trial_prime_index] == 0:
                            proof.append(primes[trial_prime_index])
                            found_divisor = True
                        trial_prime_index += 1
                    if not found_divisor:
                        bad_coin = True
                else:
                    bad_coin = True
                if bad_coin:
                    print('prime in base {}'.format(base))
                    break
            if not bad_coin:
                print(trial_coin, proof)
                coins[trial_coin] = proof
    return coins


# Copyright (c) 2012 the authors listed at the following URL, and/or
# the authors of referenced articles or incorporated external code:
# http://en.literateprograms.org/Miller-Rabin_primality_test_(Python)
#
# Permission is hereby granted, free of charge, to any person obtaining
# a copy of this software and associated documentation files (the
# "Software"), to deal in the Software without restriction, including
# without limitation the rights to use, copy, modify, merge, publish,
# distribute, sublicense, and/or sell copies of the Software, and to
# permit persons to whom the Software is furnished to do so, subject to
# the following conditions:
#
# The above copyright notice and this permission notice shall be
# included in all copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
# EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
# MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
# IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
# CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
# TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
# SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
#
# Retrieved from:
# http://en.literateprograms.org/Miller-Rabin_primality_test_(Python)
#



def miller_rabin_pass(a, s, d, n):
    a_to_power = pow(a, d, n)
    if a_to_power == 1:
        return True
    for i in range(s-1):
        if a_to_power == n - 1:
            return True
        a_to_power = (a_to_power * a_to_power) % n
    return a_to_power == n - 1


def miller_rabin(n):
    """
    Primality test using Miller-Rabin method.
    n The number to test primality.
    """

    d = n - 1
    s = 0
    while d % 2 == 0:
        d >>= 1
        s += 1

    for repeat in range(20):
        a = 0
        while a == 0:
            a = random.randrange(n)
        if not miller_rabin_pass(a, s, d, n):
            return False
    return True

main()