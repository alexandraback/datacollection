def solve(values):
    """

    :param values: sequence of ints, number of people in ascending shy levels
    :return: required friends

    >>> solve((1, 1, 1, 1, 1))
    0
    >>> solve((0, 9))
    1
    >>> solve((1, 1, 0, 0, 1, 1))
    2
    >>> solve((1,))
    0
    """
    friends = 0
    standing = 0
    for si, x in enumerate(values):
        if x and si > standing:
            needed = si - standing
            friends += needed
            standing += needed
        standing += x
    return friends


if __name__ == "__main__":
    T = int(input())
    for i in range(T):
        values = [int(x) for x in input().split()[-1]]
        print("Case #{}: {}".format(i + 1, solve(values)))
