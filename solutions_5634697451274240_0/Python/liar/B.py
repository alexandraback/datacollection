from itertools import groupby

def solve(pancakes):
    flips_count = sum(1 for k, g in groupby(pancakes)) - 1
    extra_flips = ((pancakes[0] == "-") + flips_count) % 2
    return flips_count + extra_flips

def parse_problems():
    import fileinput
    fin = fileinput.input()

    T = int(next(fin))
    for _ in range(T):
        yield next(fin).strip()

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