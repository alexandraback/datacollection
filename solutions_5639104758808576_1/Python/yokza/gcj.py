#!/usr/bin/python

read_int = lambda: int(raw_input())


def solve_case(numc):
    _, levels = raw_input().split()
    invited = nums = 0
    for level, num in enumerate(levels):
        if nums < level:
            invited, nums = invited + (level - nums), level
        nums += int(num)
    print "Case #{}:".format(numc), invited


def main():
    for i in xrange(1, read_int() + 1):
        solve_case(i)


if __name__ == '__main__':
    main()