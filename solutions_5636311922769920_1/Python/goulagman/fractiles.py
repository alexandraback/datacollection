import itertools


def read_n_int(n):
    ints = [int(s) for s in input().split(" ")]
    if len(ints) != n:
        raise ValueError('Expected %i ints, got %i' % (n, len(ints)))
    return ints


def groupiter(n, iterable, fillvalue=None):
    args = [iter(iterable)] * n
    return itertools.zip_longest(fillvalue=fillvalue, *args)


def repr_in_base(digits, base):
    # Take a list of digits in base 10 and give the base 10 representation of
    # the number composed of the digits in the given base.
    s = 0
    for digit in digits:
        s = s * base + digit
    return s


t = int(input())  # read a line with a single integer
for i in range(1, t + 1):
    k, c, s = read_n_int(3)
    if s < (k / c):
        print("Case #%i: IMPOSSIBLE" % i)
        continue
    pos = []
    for group in groupiter(c, range(k), fillvalue=0):
        pos.append(str(repr_in_base(group, k) + 1))

    print("Case #{}: {}".format(i, ' '.join(pos)))
