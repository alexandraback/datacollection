import sys


def sheep(number):
    i = 0
    seen = set()
    for _ in range(1000):
        i += number
        seen |= set(str(i))
        if len(seen) == 10:
            return i
    return 'INSOMNIA'


def main():
    name = sys.argv[1]
    with open(name, 'r') as f:
        content = f.read()
    lines = content.splitlines()
    num = lines[0]
    result = ''
    for n in range(int(num)):
        case = int(lines[1 + n])
        result += 'Case #{}: {}\n'.format(1 + n, sheep(case))
    with open(name.replace('in', 'sol'), 'w') as f:
        f.write(result)


def test():
    cases = {
        0: 'INSOMNIA',
        1: 10,
        2: 90,
        11: 110,
        1692: 5076,
    }
    for inp, expected in cases.items():
        actual = sheep(inp)
        assert actual == expected, 'Got {}, expected {} on {}'.format(actual, expected, inp)


if __name__ == '__main__':
    main()
