import doctest


def reverse(xs, n):
    """
        >>> reverse([0, 1, 0, 1], 1)
        (1, 1, 0, 1)
        >>> reverse([0, 1, 0, 1], 2)
        (0, 1, 0, 1)
        >>> reverse([0, 1, 0, 1], 3)
        (1, 0, 1, 1)
        >>> reverse([0, 1, 0, 1], 4)
        (0, 1, 0, 1)
    """
    ret = [None] * len(xs)
    for i in xrange(n):
        ret[i] = 1 - xs[n - 1 - i]
    for i in xrange(n, len(xs)):
        ret[i] = xs[i]
    return tuple(ret)

doctest.testmod()

T = int(raw_input())
for t in xrange(T):
    S = raw_input()
    xs = tuple('-+'.index(c) for c in S)

    from collections import deque

    done = set()
    done.add(xs)
    deq = deque()
    deq.append((xs, 0))
    while deq:
        xs, n = deq.popleft()
        if all(xs):
            answer = n
            break
        done.add(xs)
        for i in xrange(len(xs)):
            next_xs = reverse(xs, i + 1)
            if next_xs not in done:
                deq.append((next_xs, n + 1))

    print 'Case #{}: {}'.format(t + 1, answer)
