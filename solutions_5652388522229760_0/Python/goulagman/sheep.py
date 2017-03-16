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
    if n == 0:
        print("Case #%i: INSOMNIA" % i)
        continue

    digits = np.zeros(10, dtype=bool)
    i_n = n
    for j in range(10000):
        digits_of_n = [int(s) for s in str(i_n)]
        digits[np.asarray(digits_of_n)] = True
        if np.all(digits):
            break
        i_n += n

    if np.all(digits):
        print("Case #{}: {}".format(i, i_n))
    else:
        print("Case #%i: INSOMNIA" % i)
