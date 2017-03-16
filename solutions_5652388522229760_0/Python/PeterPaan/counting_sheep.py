#!/usr/bin/python3
import sys

def add_digits(nb, digits):
    for c in '{}'.format(nb):
        digits.add(c)

def main():
    nb_tc = sys.stdin.readline()
    tc = 1
    for line in sys.stdin:
        nb_init = nb = int(line.strip())
        if nb_init == 0:
            print("Case #{}: INSOMNIA".format(tc, nb))
        else:
            digits = set()
            add_digits(nb_init, digits)
            while len(digits) < 10:
                nb += nb_init
                add_digits(nb, digits)
            print("Case #{}: {}".format(tc, nb))
        tc += 1


main()
