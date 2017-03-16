import sys
from itertools import groupby
from collections import defaultdict
from math import factorial


MOD = 1000000007


def solve(cars):
    all_letters = set()
    letters_single = defaultdict(set)
    letters_left = defaultdict(set)
    letters_right = defaultdict(set)
    letters_middle = defaultdict(set)
    for n, car in enumerate(cars):
        letters = [letter for (letter, _) in groupby(car)]
        all_letters.add(letter)
        if len(letters) == 1:
            letters_single[letters[0]].add(n)
        else:
            letters_left[letters[0]].add(n)
            letters_right[letters[-1]].add(n)
        if len(letters) >= 3:
            for letter in letters[1:-1]:
                letters_middle[letter].add(n)

    # Letter is repeated
    for letter, group in letters_middle.items():
        if (len(group) > 1
                or letter in letters_left
                or letter in letters_right
                or letter in letters_single):
            return 0

    for letter, group in letters_left.items():
        if len(group) > 1:
            return 0

    for letter, group in letters_right.items():
        if len(group) > 1:
            return 0

    cars_full_single = set()
    for v in letters_single.values():
        cars_full_single = cars_full_single.union(v)
    # print 'FULL SINGLE', cars_full_single
    cars_single = defaultdict(int)
    connected = []
    connected_starts = {}
    connected_ends = {}

    # print letters_single, letters_left, letters_right, letters_middle
    for car_nr, car in enumerate(cars):
        if car_nr in cars_full_single:
            cars_single[car[0]] += 1
        elif car[-1] in connected_starts:
            idx = connected_starts[car[-1]]
            connected[idx] = car + connected[idx]
            del connected_starts[car[-1]]
            connected_starts[car[0]] = idx
        elif car[0] in connected_ends:
            idx = connected_ends[car[0]]
            connected[idx] = connected[idx] + car
            del connected_ends[car[0]]
            connected_ends[car[-1]] = idx
        else:
            connected.append(car)
            idx = len(connected) - 1
            connected_starts[car[0]] = idx
            connected_ends[car[-1]] = idx
        # print connected, connected_starts, connected_ends

    # print connected, cars_single

    visited = set()
    for letter, idx1 in connected_starts.items():
        if letter in connected_ends:
            idx2 = connected_ends[letter]
            if idx2 in visited:
                continue
            if idx1 == idx2:
                return 0
            # print idx1, idx2, connected
            connected[idx1] = connected[idx2] + connected[idx1]
            visited.add(idx2)

    connected = [x for (i, x) in enumerate(connected) if i not in visited]

    for c in connected:
        if c[0] == c[-1]:
            return 0

    cars_single_wherever = [letter for letter in cars_single
                            if letter not in letters_left
                            and letter not in letters_right]
    result = factorial(len(connected) + len(cars_single_wherever)) % MOD
    for letter, count in cars_single.items():
        result = result * factorial(count) % MOD

    return result


if __name__ == '__main__':
    case_count = int(sys.stdin.readline()[:-1])
    for i in range(1, case_count + 1):
        _ = sys.stdin.readline()
        cars = sys.stdin.readline().split()
        print "Case #%d: %s" % (i, solve(cars))
