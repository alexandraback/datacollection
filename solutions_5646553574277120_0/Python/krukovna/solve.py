import sys


class Solved(Exception):
    pass


def check(value, items):
    s = value
    for i in range(0, len(items)):
        if s >= items[i]:
            s -= items[i]

    return s == 0


def solve(top, items):
    a = 0
    items = list(reversed(items))
    for i in range(1, top+1):
        if not check(i, items):
            items = list(reversed(sorted([i] + items)))
            a += 1

    raise Solved(a)


if __name__ == '__main__':
    for i in range(int(sys.stdin.readline())):
        data = list(map(int, sys.stdin.readline().strip().split(' ')))
        amounts = list(sorted(map(int, sys.stdin.readline().strip().split(' '))))

        try:
            solve(data[2], amounts)
        except Solved as e:
            print('Case #{}: {}'.format(i+1, e))
