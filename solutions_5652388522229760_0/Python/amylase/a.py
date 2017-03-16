def solve(x):
    """
    >>> solve(0)
    'INSOMNIA'
    >>> solve(1)
    10
    >>> solve(2)
    90
    """
    if x == 0:
        return "INSOMNIA"
    seen = set()
    for i in xrange(1, 10 ** 6):
        seen.update(list(str(x * i)))
        if len(seen) == 10:
            return x * i


if __name__ == '__main__':
    n = input()
    for i in xrange(n):
        case_num = i + 1
        print "Case #{}: {}".format(case_num, solve(input()))