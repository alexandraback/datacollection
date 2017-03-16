#!/usr/bin/python3

import sys
from collections import Counter

def main():
    nbtc = sys.stdin.readline()
    for it,line in enumerate(sys.stdin.readlines()):
        tc = it + 1
        line = line.strip()
        c = Counter(line)
        ZERO = c['Z']
        SIX = c['X']
        FOUR = c['U']
        TWO = c['W']
        EIGHT = c['G']
        SEVEN = c['S'] - SIX
        FIVE = c['V'] - SEVEN
        THREE = c['H'] - EIGHT
        NINE = c['I'] - (FIVE + SIX + EIGHT)
        ONE = c['N'] - (SEVEN + 2 * NINE)
        sys.stdout.write("Case #{}: ".format(tc))
        sys.stdout.write('0' * ZERO)
        sys.stdout.write('1' * ONE)
        sys.stdout.write('2' * TWO)
        sys.stdout.write('3' * THREE)
        sys.stdout.write('4' * FOUR)
        sys.stdout.write('5' * FIVE)
        sys.stdout.write('6' * SIX)
        sys.stdout.write('7' * SEVEN)
        sys.stdout.write('8' * EIGHT)
        sys.stdout.write('9' * NINE)
        sys.stdout.write('\n')
main()
