#!/usr/bin/env python

MOD = 1000000007

fac = [1]
for x in range(1, 110):
    y = fac[-1] * x % MOD
    fac.append(y)

def ReadIn():
    cases = int(input().strip())
    for case in range(1, cases + 1):
        n = int(input().strip())
        cars = input().split()
        yield case, cars

def parse(car, enters, exits, passes, noends):
    if all(c == car[0] for c in car):
        if car[0] not in passes: passes[car[0]] = 0
        passes[car[0]] += 1
        return
    for enter in range(len(car)):
        if car[enter] == car[0]:
            enterEnd = enter
            enterChar = car[enter]
        else:
            break
    for exit in range(len(car) - 1, -1, -1):
        if car[exit] == car[-1]:
            exitEnd = exit;
            exitChar = car[exit]
    for idx in range(enterEnd + 1, exitEnd):
        noends[car[idx]] = True
    if enterChar not in enters: enters[enterChar] = 0
    enters[enterChar] += 1
    if exitChar not in exits: exits[exitChar] = 0
    exits[exitChar] += 1

def Solve(cars):
    enters = {}
    exits = {}
    passes = {}
    noends = {}
    for car in cars:
        parse(car, enters, exits, passes, noends)
    for c in noends:
        if c in enters or c in exits or c in passes:
            return 0
    for c in enters:
        if enters[c] > 1:
            return 0
    for c in exits:
        if exits[c] > 1:
            return 0
    ret = 1
    parts = len(cars)
    for c in passes:
        parts -= passes[c] - 1
        ret = ret * fac[passes[c]] % MOD
        if c in enters or c in exits:
            parts -= 1
    for c in enters:
        if c in exits: parts -= 1
    ret = ret * fac[parts] % MOD
    return ret

if __name__ == '__main__':
    for case, cars in ReadIn():
        print('Case #%d: %d' % (case, Solve(cars)))
