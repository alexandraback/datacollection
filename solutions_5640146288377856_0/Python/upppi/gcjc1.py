from __future__ import print_function
import fileinput


def battle(r, c, w):
    simple = r * (c / w)
    ship = (w - 1)
    if(c % w):
        ship += 1
    return simple + ship


def solve(line):
    r, c, w = map(int, line.split())
    return battle(r, c, w)


def main():
    for idx, line in enumerate(fileinput.input()):
        if idx > 0:
            print("Case #", idx, ": ", solve(line))

if __name__ == '__main__':
    main()
