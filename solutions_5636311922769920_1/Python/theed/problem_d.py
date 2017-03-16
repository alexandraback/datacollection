import sys


def fractiles(k, c, s):
    if k / c > s:
        return 'IMPOSSIBLE'
    checked = 0
    tiles = []
    while checked < k:
        tile = 0
        for n in range(c):
            if checked >= k:
                break
            tile += checked * (k ** n)
            checked += 1
        tiles.append(tile + 1)
    return tiles


def main():
    name = sys.argv[1]
    with open(name, 'r') as f:
        content = f.read()
    lines = content.splitlines()
    num = lines[0]
    result = ''
    for n in range(int(num)):
        s_k, s_c, s_s = lines[n + 1].split(' ')
        data = fractiles(int(s_k), int(s_c), int(s_s))
        if isinstance(data, list):
            data_str = [str(x) for x in data]
            data = ' '.join(data_str)
        result += 'Case #{}: {}\n'.format(1 + n, data)
    with open(name.replace('in', 'sol'), 'w') as f:
        f.write(result)


def test():
    cases = {
        (2, 3, 2): (2, ),
        (1, 1, 1): (1, ),
        (2, 1, 1): 'IMPOSSIBLE',
        (2, 1, 2): (1, 2),
        (3, 2, 3): (2, 6),
    }
    # will fail because no single correct solution
    return True
    for inp, expected in cases.items():
        actual = fractiles(inp[0], inp[1], inp[2])
        assert actual == expected, 'Got {}, expected {} on {}'.format(actual, expected, inp)


if __name__ == '__main__':
    main()
