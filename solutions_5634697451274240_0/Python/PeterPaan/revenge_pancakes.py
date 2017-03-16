#!/usr/bin/python3
import sys

def add_digits(nb, digits):
    for c in '{}'.format(nb):
        digits.add(c)

def main():
    nb_tc = sys.stdin.readline()
    tc = 1
    for line in sys.stdin:
        line = line.strip()
        prev = line[0]
        transitions = 0
        for c in line[1:]:
            if c != prev:
                transitions += 1
                prev = c
        if line[-1] == '-':
            res = transitions + 1
        else:
            res = transitions
        print("Case #{}: {}".format(tc, res))
        tc += 1


main()
