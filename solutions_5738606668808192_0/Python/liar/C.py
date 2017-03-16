import array
import itertools
import logging

def solve(problem):
    N, J = problem
    assert N % 2 == 0

    L = 10 ** (N // 2)
    sieve = array.array('B', (1 for i in range(L)))
    sieve[0] = 0
    sieve[1] = 0
    for p in itertools.count(2):
        if p * p >= L:
            break
        if sieve[p]:
            for k in range(p * p, L, p):
                sieve[k] = 0
    primes = [p for p in range(2, L) if sieve[p]]
    logging.info("Primes computed ({})", len(primes))

    def find_divisor(n):
        for p in primes:
            m, r = divmod(n, p)
            if r == 0:
                return p
            if m <= p:
                break
        return None

    def jamcoins():
        bases = list(range(2, 11))
        for n in range(2 ** (N - 1) + 1, 2 ** N, 2):
            coin = "{:b}".format(n)
            divisors = {}
            for base in bases:
                v = int(coin, base=base)
                d = find_divisor(v)
                if d is None:
                    break

                assert v % d == 0
                divisors[base] = d

            if len(divisors) < len(bases):
                continue

            components = [coin]
            logging.info(coin)
            for b in bases:
                logging.info("  {:>2}: {} | {}".format(b, divisors[b], int(coin, base=b)))
                components.append(str(divisors[b]))
            yield " ".join(components)

    lines = [""]
    for i, jc in enumerate(jamcoins()):
        if i >= J:
            break
        lines.append(jc)
    return "\n".join(lines)


def parse_problems():
    import fileinput
    fin = fileinput.input()

    T = int(next(fin))
    for _ in range(T):
        yield list(map(int, next(fin).split()))

def main():
    import time
    logging.basicConfig(level=logging.INFO, format="%(message)s")

    t0 = time.time()
    logging.info("Starting...")
    for i, p in enumerate(parse_problems()):
        ans = solve(p)
        logging.info("Solved #%d", i + 1)
        print("Case #{}: {}".format(i + 1, ans))
    logging.info("Finished in %.2f s", time.time() - t0)

if __name__ == '__main__':
    main()