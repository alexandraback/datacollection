def number_from_digits(digits, base):
    ans = 0
    for d in digits:
        ans = ans * base + d
    return ans

def solve(problem):
    K, C, S = problem
    assert 1 <= S <= K
    if S * C < K:
        return "IMPOSSIBLE"

    tile_positions = [list(range(k, min(k + C, K))) for k in range(0, K, C)]
    return " ".join(str(1 + number_from_digits(digits, K)) for digits in tile_positions)

def parse_problems():
    import fileinput
    fin = fileinput.input()

    T = int(next(fin))
    for _ in range(T):
        yield list(map(int, next(fin).split()))

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