import sys
import os


def problem_specific_parser(src):
    return [float(e) for e in next(src).split(" ")]


def solve(data):
    c, f, x = data
    cookie_production = 2

    nfarms  = 0
    best_time = x / cookie_production
    t = 0

    while (True):
        next_time = c / cookie_production
        if (t + next_time + (x / (cookie_production + f))) < best_time:
            t += next_time
            cookie_production += f
            best_time = t + x / cookie_production
        else:
            return best_time


def parse(src):
    lines = iter(src.split(os.linesep))
    nproblems = int(next(lines))

    for problem in range(nproblems):
        yield problem_specific_parser(lines)


def main():
    src = sys.stdin.read()
    for i, data in enumerate(parse(src)):
        print("Case #{0}: {1}".format(i + 1, solve(data)))

    
if __name__ == '__main__':
    main()
