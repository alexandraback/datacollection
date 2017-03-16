from itertools import cycle


def to_output(result):
    if result:
        return " ".join(map(str, result))
    else:
        return "IMPOSSIBLE"


def process(input_file, out):
    t = int(input_file.readline())

    for i in range(1, t + 1):
        input_line = input_file.readline().strip()
        k, c, s = map(int, input_line.split(" "))
        result = solve(k, c, s)
        out.write("Case #%s: %s\n" % (i, to_output(result)))


def ceil_div(a, b):
    div, mod = divmod(a, b)
    if mod:
        return div + 1
    else:
        return div


def solve(k, c, s):
    checks = ceil_div(k, c)

    if s < checks:
        return None
    else:
        branches = cycle(range(k))
        tiles = []

        for _ in range(checks):
            tile = 0
            for _ in range(c):
                tile *= k
                tile += next(branches)

            tiles.append(tile + 1)

        return tiles

