import sys
from itertools import permutations

sys.stdin = open("input.txt")
sys.stdout = open("output.txt", "w+")


def all_same(s):
    return s.count(s[0]) == len(s)


def is_valid(string):
    occured = {}

    prev = "*"
    for char in string:
        if char in occured and char != prev:
            return False

        occured[char] = 1
        prev = char

    return True


def solve(car):
    count = 0
    for l in permutations(car):
        count += is_valid("".join(l))
    return count


for case in range(1, input() + 1):
    input();

    car = []
    for s in raw_input().split():
        p, r = "", ""
        for i in s:
            if i == p:
                continue
            r = r + i
            p = i
        car.append(r)

    print >> sys.stderr, "Case #%s: %s %s" % (case, len(car), car)

    print "Case #%s: %s" % (case, solve(car))
