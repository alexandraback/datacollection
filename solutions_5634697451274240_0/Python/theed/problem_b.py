import sys


def flips(inp):
    inp += '+'
    result = 0
    for i in range(1, len(inp)):
        if inp[i] != inp[i - 1]:
            result += 1
    return result


def main():
    name = sys.argv[1]
    with open(name, 'r') as f:
        content = f.read()
    lines = content.splitlines()
    num = lines[0]
    result = ''
    for n in range(int(num)):
        case = lines[1 + n]
        result += 'Case #{}: {}\n'.format(1 + n, flips(case))
    with open(name.replace('in', 'sol'), 'w') as f:
        f.write(result)


def test():
    cases = {
        '-': 1,
        '-+': 1,
        '+-': 2,
        '+++': 0,
        '--+-': 3,
    }
    for inp, expected in cases.items():
        actual = flips(inp)
        assert actual == expected, 'Got {}, expected {} on {}'.format(actual, expected, inp)


if __name__ == '__main__':
    main()
