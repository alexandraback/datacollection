def solve(N):
    if N == 0:
        return "INSOMNIA"

    not_seen_digits = set(range(10))

    def digits_set(n):
        ans = set()
        while True:
            ans.add(n % 10)
            n //= 10
            if n == 0:
                break
        return ans

    from itertools import count
    for k in count(1):
        not_seen_digits -= digits_set(k * N)
        if len(not_seen_digits) == 0:
            return k * N

def parse_problems():
    import fileinput
    fin = fileinput.input()

    T = int(next(fin))
    for _ in range(T):
        N = int(next(fin))
        yield N

def main():
    import time
    import logging
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