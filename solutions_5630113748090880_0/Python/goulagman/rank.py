import numpy as np


def read_n_int(n):
    ints = [int(s) for s in input().split(" ")]
    if len(ints) != n:
        raise ValueError('Expected %i ints, got %i' % (n, len(ints)))
    if n == 1:
        return ints[0]
    return ints


t = read_n_int(1)
for i in range(1, t + 1):
    n = read_n_int(1)
    numbers = []
    for j in range(2 * n - 1):
        numbers.extend(read_n_int(n))
    line = np.where((np.bincount(numbers) % 2) == 1)[0]
    print("Case #%i: %s" % (i, ' '.join([str(j) for j in line])))
