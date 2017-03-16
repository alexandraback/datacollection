import math

import problem


def prime_sieve(prime_count=1000):
    n = 1
    found = []

    while len(found) < prime_count:
        n += 1
        limit = int(math.sqrt(n))
        prime = True
        for divisor in found:
            if n % divisor == 0:
                prime = False
                break
            if divisor > limit:
                break
        if prime:
            found.append(n)

    return tuple(found)


class CoinJam(problem.Problem):

    def solve(self, case):
        N, J = case
        inner = 0
        bases = range(2, 10+1)
        max_coin = (1 << N) - 1
        primes = prime_sieve(1000)
        found = []

        while len(found) < J:
            coin = (1 << (N - 1)) + (inner << 1) + 1
            if coin > max_coin:
                raise RuntimeError('search did not yield enough results')

            divisors = {}

            for base in bases:
                number = int(format(coin, 'b'), base)
                for prime in primes:
                    if number % prime == 0:
                        divisors[base] = prime
                        break
                    if prime >= number:
                        break

            if len(divisors) == len(bases):
                # A jamcoin found!
                found.append((format(coin, 'b'),) +
                             tuple(divisors[base] for base in bases))

            inner += 1

        return found

    def parse_case(self, lines):
        return map(int, lines.next().split())

    def print_report(self, verbose=False):
        for index, case in enumerate(self.cases):
            print "Case #{0}:".format(index + 1)
            for jamcoin in self.solve(case):
                print ' '.join(map(str, jamcoin))


if __name__ == '__main__':
    # CoinJam.run_sample('1\n6 8')
    CoinJam.run()
