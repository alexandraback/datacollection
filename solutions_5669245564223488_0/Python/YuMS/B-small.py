from itertools import permutations, groupby
from math import factorial


def solve():
    N = input()
    cars = raw_input().strip().split()
    counter = 0
    for i in xrange(N):
        cars[i] = ''.join([x for x, _ in groupby(cars[i])])
    cars_set = set(cars)
    cars_dict = {}
    for car in cars_set:
        cars_dict[car] = 0
        for c in cars:
            if c == car:
                cars_dict[car] += 1
                if cars_dict[car] > 1 and len(car) > 1:
                    return 0
    for cars_per in permutations(cars_set):
        cars_join = ''.join(cars_per)
        work = len(set(cars_join)) == \
            sum([1 for x in groupby(cars_join)])
        # print cars_per
        # print work
        if work:
            counter += 1
    for key, value in cars_dict.iteritems():
        counter *= factorial(value)
    return counter % 1000000007


def main():
    T = input()
    for i in xrange(1, T + 1):
        num = solve()
        print 'Case #%d:' % i,
        print num


if __name__ == '__main__':
    main()
