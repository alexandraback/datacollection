import sys

def count_shill(xs):
    """
    count_shill(xs: [int]) -> int
    """
    shill = 0
    standing = 0
    for (k, ppl) in enumerate(xs):
        if standing < k:
            shill += k - standing
            standing = k
        standing += ppl
    return shill


def parse(txt):
    """
    parse(txt: str) -> [[int]]
    """
    rest = txt[1:]
    out = [list(map(int, line.split()[-1])) for line in rest]
    return out


if __name__ == '__main__':
    with open(sys.argv[1], "r") as f:
        data = parse(list(f))

    ns = [count_shill(shyness_levels) for shyness_levels in data]
    for (i, n) in enumerate(ns):
        print("Case #%d: %d" % (i + 1, n))
