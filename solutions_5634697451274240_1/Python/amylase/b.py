def solve(s):
    """
    >>> solve('+++')
    0
    >>> solve('-+')
    1
    >>> solve('+-')
    2
    >>> solve('--+-')
    3
    """
    return len(list(0 for p, q in zip(s[:-1], s[1:]) if p != q)) + (1 if s[-1] == '-' else 0)


if __name__ == '__main__':
    n = input()
    for i in xrange(n):
        case_num = i + 1
        print "Case #{}: {}".format(case_num, solve(raw_input().strip()))