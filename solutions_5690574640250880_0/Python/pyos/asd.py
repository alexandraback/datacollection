from sys import stdin


_readstr  = lambda: stdin.readline().strip()
_readlist = lambda: stdin.readline().split()
_readint  = lambda: int(_readstr())


def solve(w, h, q, ys):
    # See below for a description.
    if not q:
        return ys

    if len(ys) >= h:
        return None

    for z in range(min(q, ys[-1]), 1, -1):
        xs = solve(w, h, q - z, ys + [z])

        if xs:
            return xs

    return None



for n in range(_readint()):
    h, w, c = map(int, _readlist())
    # Let `q = w * h - c` be the number of empty cells.
    q = w * h - c

    print('Case #{}:'.format(n + 1))

    # Then it's possible to open them in one click iff:
    # 1. Grid is of size 1 in any dimension.
    if   h == 1: ys = [q]
    elif w == 1: ys = [1] * q
    # 2. There is only one empty cell (obviously.)
    elif q == 1: ys = [1]
    # 3. it's possible to make a list of at most `h` numbers `i(y)` where
    #
    #   1. sum of them is `q`;
    #   2. `2 <= i(y) <= w`;
    #   3. `i(0) == i(1)`;
    #   4. `i(y - 1) >= i(y)` for all possible `y > 1`.
    #
    # `i(y)` will then be the number of empty cells in row `y`.
    #
    else:
        for y0 in range(min(w, q // 2), 1, -1):
            ys = solve(w, h, q - y0 * 2, [y0, y0])

            if ys:
                break
        else:
            print('Impossible')
            continue

    for i, y in enumerate(ys):
        print(('.' if i else 'c') + '.' * (y - 1) + '*' * (w - y))
    for _ in range(h - len(ys)):
        print('*' * w)
