import logging

from blist import sortedlist


logging.basicConfig(level=logging.DEBUG)
logger = logging.getLogger(__name__)


def split(x):
    i = x // 2
    while True:
        yield x - i, i
        i -= 1
        if i == 0:
            return


def update(l, *args):
    l.update(args)
    return l


cache = {}


def _solve(plates):
    """
    :param plates: a sequence of sorted plates in descending order
    :return: number of minutes needed
    """
    x = plates[-1]
    assert x > 0
    if x <= 3:
        return x

    _plates = tuple([p for p in plates if p >= 3])

    if _plates in cache:
        # print("HIT", _plates, cache[_plates])
        return cache[_plates]

    best = x
    for x1, x2 in split(x):
        attempt = _solve(update(plates[:-1], x1, x2)) + 1
        if attempt < best:
            best = attempt
    # print("MISS", _plates, best)
    cache[_plates] = best
    return best


def solve(plates):
    return _solve(sortedlist(plates))


if __name__ == "__main__":
    T = int(input())
    for i in range(T):
        D = int(input())
        values = [int(x) for x in input().split()]
        print("Case #{}: {}".format(i + 1, solve(values)))
        logger.debug("Case #{}. Cache: {}".format(i + 1, len(cache)))
