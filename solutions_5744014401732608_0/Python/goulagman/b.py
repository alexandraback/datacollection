from scipy.misc import comb
import numpy as np


def read_n_int(n):
    ints = [int(s) for s in input().split(" ")]
    if len(ints) != n:
        raise ValueError('Expected %i ints, got %i' % (n, len(ints)))
    if n == 1:
        return ints[0]
    return ints


def compute_max(k):
    n = k - 2
    return np.sum(comb(n, m, True) for m in range(k - 1))


def att(m, gin, gout, gall, p, q, dm):
    m -= dm
    gall[p, q] = 1

    if m == 0:
        print(gall)
        return True

    # Increment out for all successors
    j = [q]
    inc = gin[p]
    while len(j) > 0:
        r = j.pop(0)
        if r == (b - 1):
            continue
        gin[r] += inc
        j.extend(list(np.where(gall[r, :] == 1)[0]))

    # Increment out for all ancestors
    j = [p]
    inc = gout[q]
    while len(j) > 0:
        r = j.pop(0)
        if r == 0:
            continue
        gout[r] += inc
        j.extend(list(np.where(gall[:, r] == 1)[0]))

    # Power matrix
    pm = np.dot(gin[:, None], gout[None, :])
    # No retrolink, avoid cycles
    pm = np.triu(pm, 1)
    # print('-----------------')
    # print(pm)
    # print(gall)
    pm[gall == 1] = 0
    # print(pm)

    # Remove connections with too many links
    pm[pm > m] = 0

    if np.all(pm == 0):
        return False

    if np.any(pm == m):
        p = np.where(pm == m)[0][0]
        q = np.where(pm == m)[1][0]
        att(m, gin.copy(), gout.copy(), gall.copy(), p, q, pm[p, q])
        return True

    for p, q in zip(*np.where(pm > 0)):
        res = att(m, gin.copy(), gout.copy(), gall.copy(), p, q, pm[p, q])
        if res:
            return res


t = read_n_int(1)
for i in range(1, t + 1):
    b, m = read_n_int(2)
    if m > compute_max(b):
        print("Case #%i: IMPOSSIBLE" % i)
        continue
    print("Case #%i: POSSIBLE" % i)
    gin = np.zeros(b, dtype=int)
    gout = np.zeros(b, dtype=int)
    gall = np.zeros((b, b), dtype=int)

    # First blood
    gall[0, b - 1] = 1
    m -= 1

    # Simple connections
    j = 1
    while m > 0 and j < (b - 1):
        gall[0, j] = 1
        gall[j, b - 1] = 1
        gin[j] = 1
        gout[j] = 1
        j += 1
        m -= 1

    if m == 0:
        print(gall)
        continue
    # Power matrix
    pm = np.dot(gin[:, None], gout[None, :])
    # No retrolink, avoid cycles
    pm = np.triu(pm, 1)
    # print('-----------------')
    # print(pm)
    # print(gall)
    pm[gall == 1] = 0
    # print(pm)

    # Remove connections with too many links
    pm[pm > m] = 0

    for p, q in zip(*np.where(pm > 0)):
        res = att(m, gin.copy(), gout.copy(), gall.copy(), p, q, pm[p, q])
        if res:
            break
