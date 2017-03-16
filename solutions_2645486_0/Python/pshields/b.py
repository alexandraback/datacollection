import sys


def max_gain(e0, r, n, v):
    """
    To maximize gain, maximize the amount of energy spent on the most valuable
    task, then the second most valuable, and so on.
    """

    # store how much energy is available at each task
    e = [e0] * n

    # store how much energy is committed for future tasks at each task
    committed = [0] * n

    # track expenditures at each task
    expend = [0] * n

    def schedule(i):
        """Schedule the maximum amount of energy available for task i to task i."""

        expend[i] = e[i] - committed[i]
        e[i] -= expend[i]
        committed[i] += expend[i]
        j = i + 1
        if expend[i] > 0:
            while j < n:
                e[j] = min(e[j - 1] + r, e0 - expend[j])
                if e[j] == e0 or e[j] == 0:
                    # The remaining energy levels in this direction don't need adjustment.
                    break
                j += 1
            j = i - 1
            while j >= 0:
                committed[j] = max(committed[j], committed[j + 1] - r)
                if e[j]  == 0:
                    # The remaining energy levels in this direction don't need adjustment.
                    break
                j -= 1

    # Get a list of v's indices in nonincreasing order of the value at that index
    vi = [x[0] for x in sorted(enumerate(v), key=lambda x: x[1], reverse=True)]
    
    # Schedule the tasks.
    for i in vi:
        schedule(i)

    return sum(v[i] * expend[i] for i in range(n))


if __name__ == '__main__':
    T = int(sys.stdin.readline())
    for z in range(1, T + 1):
        e, r, n = [int(x) for x in sys.stdin.readline().split()]
        v = [int(x) for x in sys.stdin.readline().split()]
        result = max_gain(e, r, n, v)
        print("Case #%d: %d" % (z, result))
