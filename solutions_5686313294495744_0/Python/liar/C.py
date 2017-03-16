import logging
from collections import Counter

def solve(topics):
    topics = set(topics)

    v1 = set(w1 for w1, w2 in topics)
    v2 = set(w2 for w1, w2 in topics)

    c1 = Counter(w1 for w1, w2 in topics)
    c2 = Counter(w2 for w1, w2 in topics)

    def find_fake(topics):
        for t in topics:
            w1, w2 = t
            if c1[w1] > 1 and c2[w2] > 1:
                return t

    ans = 0
    while True:
        t = find_fake(topics)
        if not t:
            return ans
        w1, w2 = t
        c1[w1] -= 1
        c2[w2] -= 1
        ans += 1
        topics.remove(t)

    return ans

def parse_problems():
    import fileinput
    fin = fileinput.input()

    T = int(next(fin))
    for _ in range(T):
        N = int(next(fin))
        topics = []
        for _ in range(N):
            w1, w2 = next(fin).strip().split()
            t = (w1, w2)
            topics.append(t)
        yield topics

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