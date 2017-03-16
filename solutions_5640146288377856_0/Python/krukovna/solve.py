import sys


class Solved(Exception):
    pass


def solve(x, y, w):
    if w == 1:
        raise Solved(x * y)

    tests = y // w
    extra = w - 1
    if tests * w != y:
        tests += 1

    raise Solved(tests + extra)


if __name__ == '__main__':
    for i in range(int(sys.stdin.readline())):
        data = list(map(int, sys.stdin.readline().strip().split(' ')))

        try:
            solve(*data)
        except Solved as e:
            print('Case #{}: {}'.format(i+1, e))
