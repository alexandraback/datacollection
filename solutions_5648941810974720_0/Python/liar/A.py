import logging
from collections import Counter

DIGIT_NAMES = [
    "ZERO",
    "ONE",
    "TWO",
    "THREE",
    "FOUR",
    "FIVE",
    "SIX",
    "SEVEN",
    "EIGHT",
    "NINE",
]

def solve(s):
    counter = Counter(s)
    ans = {}
    def guess(digit, letter):
        digits_count = counter[letter]
        ans[digit] = digits_count
        for letter in DIGIT_NAMES[digit]:
            counter[letter] -= digits_count

    guess(0, "Z")
    guess(6, "X")
    guess(4, "U")
    guess(5, "F")
    guess(8, "G")
    guess(7, "S")
    guess(9, "I")
    guess(2, "W")
    guess(1, "O")
    guess(3, "T")

    return "".join(map(lambda d: str(d) * ans[d], range(10)))

def parse_problems():
    import fileinput
    fin = fileinput.input()

    T = int(next(fin))
    for _ in range(T):
        yield next(fin).strip()

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
