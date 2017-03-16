#!/usr/bin/python2

import sys


def calculate_atacks(tribes):
    # We calculate attacks day by day, until no tribe have any attacks left
    attacks = {}
    for tribe in tribes:
        for i in xrange(0, tribe[1]):
            d = tribe[0]
            if d not in attacks:
                attacks[d] = []
            attacks[d].append((tribe[2], tribe[3], tribe[4]))
            # Change tribe status
            tribe[0] += tribe[5]
            tribe[2] += tribe[6]
            tribe[3] += tribe[6]
            tribe[4] += tribe[7]
    return attacks


def raise_wall(wall, w, e, s):
    for i in xrange(2 * w, 2 * e + 1):
        if i not in wall or wall[i] < s:
            wall[i] = s


def succeed(wall, w, e, s):
    for i in xrange(2 * w, 2 * e + 1):
        if i not in wall:
            return True
        if wall[i] < s:
            return True
    return False


def simulate_attacks(attacks):
    wall = {}
    s = 0
    for day in attacks:
        for attack in attacks[day]:
            if succeed(wall, attack[0], attack[1], attack[2]):
                s += 1
        for attack in attacks[day]:
            raise_wall(wall, attack[0], attack[1], attack[2])
    return s


def Solve():
    ntribes = int(sys.stdin.readline().strip())
    tribes = []
    for i in xrange(0, ntribes):
        d, n, w, e, s, di, pi, si = map(int, sys.stdin.readline().strip().split())
        tribes.append([d, n, w, e, s, di, pi, si])

    attacks = calculate_atacks(tribes)
    return simulate_attacks(attacks)

num = int(sys.stdin.readline())

for case in range(1, num + 1):
    print "Case #%d: %s " % (case, Solve())
