import doctest


def reverse(xs, n):
    """
        >>> reverse([0, 1, 0, 1], 1)
        [1, 1, 0, 1]
        >>> reverse([0, 1, 0, 1], 2)
        [0, 1, 0, 1]
        >>> reverse([0, 1, 0, 1], 3)
        [1, 0, 1, 1]
        >>> reverse([0, 1, 0, 1], 4)
        [0, 1, 0, 1]
    """
    ret = [None] * len(xs)
    for i in xrange(n):
        ret[i] = 1 - xs[n - 1 - i]
    for i in xrange(n, len(xs)):
        ret[i] = xs[i]
    return ret

doctest.testmod()

T = int(raw_input())
for t in xrange(T):
    S = raw_input()
    xs = ['-+'.index(c) for c in S]
    while xs and xs[-1]:
        xs[-1:] = []

    answer = 0
    while not all(xs):
        n = 1
        while n < len(xs) and xs[n] == xs[0]:
            n += 1
        xs = reverse(xs, n)
        while xs and xs[-1]:
            xs[-1:] = []
        answer += 1

    print 'Case #{}: {}'.format(t + 1, answer)
