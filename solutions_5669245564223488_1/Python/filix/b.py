#!/usr/bin/python3 -t
import itertools
import math


MOD = int(1e9 + 7)


def read_ints():
    return map(int, input().split())


def solve():
    _n = int(input())
    cars = input().split()
    grouped_cars = [list(k for k, g in itertools.groupby(car)) for car in cars]
    # print(grouped_cars)
    alpha = list(set(''.join(cars)))
    # print(cars, alpha)
    result = 1
    details = {}
    for letter in alpha:
        full, left, center, right = 0, 0, 0, 0
        for grouped_car in grouped_cars:
            if letter not in grouped_car:
                continue
            if grouped_car.count(letter) > 1:
                return 0
            if grouped_car == [letter]:
                full += 1
            elif grouped_car[0] == letter:
                left += 1
            elif grouped_car[-1] == letter:
                right += 1
            else:
                center += 1
        if center > 1:
            return 0
        if center == 1 and full + left + right > 0:
            return 0
        if left > 1 or right > 1:
            return 0
        comb = math.factorial(full) % MOD
        result = (result * comb) % MOD
        details[letter] = [full, left, center, right]
    components = {}
    for letter in alpha:
        if letter in components:
            continue
        q = [letter]
        while q:
            x = q.pop()
            for grouped_car in grouped_cars:
                if x in grouped_car:
                    for y in grouped_car:
                        if y not in components:
                            q.append(y)
                            components[y] = letter
        # parent = components.get(letter, letter)
        # components[letter] = parent
        # for grouped_car in grouped_cars:
        #     if letter not in grouped_car:
        #         continue
        #     for other in grouped_car:
        #         components[other] = parent
    # print(result)
    # print(components)
    parents = list(set(components.values()))
    for parent in parents:
        boths = 0
        ends = 0
        for k, v in components.items():
            if v != parent:
                continue
            if details[k][1] == 1 and details[k][3] == 1:
                boths += 1
            elif details[k][1] == 1 or details[k][3] == 1:
                ends += 1
        if boths > 0 and ends == 0:
            return 0
    # print(parents)
    result = (result * (math.factorial(len(parents)) % MOD)) % MOD
    return result

if __name__ == '__main__':
    for test_case in range(int(input())):
        print('Case #{}: '.format(test_case + 1), end='')
        print(solve())