import sys
import logging
from collections import Counter

logging.basicConfig(level=logging.DEBUG)
log = logging.getLogger(__name__)


counting_order = [
    ('z', 0, 'zero'),
    ('x', 6, 'six'),
    ('w', 2, 'two'),
    ('g', 8, 'eight'),
    ('h', 3, 'three'),
    ('u', 4, 'four'),
    ('s', 7, 'seven'),
    ('o', 1, 'one'),
    ('v', 5, 'five'),
    ('i', 9, 'nine'),
]


def solve(case):
    log.info('Solving: %r', case)
    case = case.lower()

    counts = dict(Counter(case))
    nums = []

    for letter, number, word in counting_order:
        n = counts.get(letter, 0)

        log.info('Doing number "%s", found %d instances', word, n)

        if n > 0:
            nums.extend([number] * n)
            for c in word:
                counts[c] -= n
                assert counts[c] >= 0, counts

    #assert sum(counts.values()) == 0, counts

    return ''.join(map(str, sorted(nums)))
            


def get_cases(lines):
    for ln in lines[1:]:
        yield ln


def main():
    lines = [ln.strip() for ln in sys.stdin]

    for i, case in enumerate(get_cases(lines), 1):
        result = solve(case)
        log.info('Case #%d: %s', i, result)
        print 'Case #%d: %s' % (i, result)


if __name__ == '__main__':
    main()
