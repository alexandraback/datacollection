from collections import defaultdict
import sys
import itertools
from itertools import permutations
from math import factorial

DEBUG = True


def hard_solver(n, cars):
    modder = 1000000007
    # membership = collections.defaultdict(set)
    # letters = string.lowercase
    # indexed_cars = dict(enumerate(cars))
    car_sets = defaultdict(list)
    for car in cars:
        sets_to_combine = []
        car_letters = set(list(car))
        for letters in car_sets:
            letter_set = set(letters)
            if letter_set & set(list(car)):
                sets_to_combine.append(letters)
        if not sets_to_combine:
            car_sets["".join(car_letters)].append(car)
        else:
            combine_sets(car_sets, sets_to_combine, car)
    ans = factorial(len(car_sets)) % modder
    for c_set in car_sets:
        ans *= car_set_perms(car_sets[c_set])
        ans %= modder
        if ans == 0:
            return ans
    return ans


def car_set_perms(car_set):
    internal_letters = set()
    beginning_cars = set()
    ending_cars = set()
    full_cars = defaultdict(int)
    for car in car_set:
        car_letters = set(list(car))
        if len(car_letters) == 1:
            full_cars[car[0]] += 1
            continue
        starting_letter = car[0]
        ending_letter = car[-1]
        if starting_letter in beginning_cars:
            return 0
        beginning_cars.add(starting_letter)
        if ending_letter in ending_cars:
            return 0
        ending_cars.add(ending_letter)

        # identify internal letters
        grouped = list(itertools.groupby(car))[1:-1]
        for l, group in grouped:
            if l in (internal_letters | beginning_cars | ending_cars | set(full_cars.keys())):
                return 0
            internal_letters.add(l)

    if len(car_set) == 1:
        if beginning_cars & ending_cars:
            return 0

    if beginning_cars:
        if (beginning_cars | ending_cars) == (beginning_cars & ending_cars):
            return 0

    ans = 1
    for k, v in full_cars.items():
        ans *= factorial(v)
    return ans


def combine_sets(car_sets, sets_to_combine, car):
    new_list = []
    new_letters = set()
    for s in sets_to_combine:
        new_list += car_sets[s]
        new_letters |= set(list(s))
        del car_sets[s]
    new_letters |= set(list(car))
    new_list.append(car)
    car_sets["".join(new_letters)] = new_list


def is_valid(car_set):
    seen = set()
    full_set = "".join(car_set)
    seen.add(full_set[0])
    for idx, l in enumerate(full_set[1:], 1):
        if full_set[idx - 1] == l:
            continue
        elif l in seen:
            return False
        seen.add(l)
    return True


def dumb_solver(n, cars):
    n = len(cars)
    perms = permutations(range(n), n)
    count = 0
    for perm in perms:
        car_set = []
        for idx in perm:
            car_set.append(cars[idx])
        if is_valid(car_set):
            count += 1
    return count % 1000000007


def ssi(s, func=int):
    """
    space separated integers
    """
    return map(func, s.strip('\n').split())


def rl():
    return sys.stdin.readline()


def debug(*args):
    if args[-1] is not False and DEBUG:
        msg = " ".join([str(m) for m in args])
        sys.stderr.write(msg + '\n')


def main():
    # open input file
    # input_file = open('infile.txt')

    cases = int(rl())
    output = []
    # loop through cases passing input to solver
    for c in xrange(cases):
        debug('Case #%d' % (c + 1))
        n = int(rl())
        cars = rl().split()
        debug(n)
        debug(cars)
        answer = hard_solver(n, cars)
        output.append('Case #%d: %s\n' % (c + 1, answer))
    # open output file
    output_file = sys.stdout
    # write ouput to file
    output_file.writelines(output)
    output_file.flush()


if __name__ == '__main__':
    main()
