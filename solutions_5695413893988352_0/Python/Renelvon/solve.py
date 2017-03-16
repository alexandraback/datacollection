#!/usr/bin/env python3
import sys


def main():
    input_file = sys.argv[1]
    solve(input_file)


def solve(input_file):
    with open(input_file) as f_in:
        t = int(next(f_in))
        for case in range(t):
            coders, jammers = next(f_in).rstrip().split()
            _, output1, output2 = solve_instance(coders, jammers)
            print("Case #%d: %s %s" % (case + 1, output1, output2))


def solve_instance(coders, jammers):
    maxd = 1000000
    flag = False
    bs1, bs2 = coders, jammers
    for i, c in enumerate(coders):
        if c == '?':
            flag = True
            sol = min(solve_instance(coders[:i] + str(n) + coders[(i + 1):], jammers) for n in range(10))
            maxdd, s1, s2 = sol
            if maxdd < maxd:
                bs1, bs2 = s1, s2
                maxd = maxdd

    if not flag:
        for i, c in enumerate(jammers):
            if c == '?':
                flag = True
                sol = min(solve_instance(coders, jammers[:i] + str(n) + jammers[(i + 1):]) for n in range(10))
                maxdd, s1, s2 = sol
                if maxdd < maxd:
                    bs1, bs2 = s1, s2
                    maxd = maxdd

    if not flag:
        maxd = abs(int(coders) - int(jammers))

    return maxd, bs1, bs2

if __name__ == '__main__':
    main()
