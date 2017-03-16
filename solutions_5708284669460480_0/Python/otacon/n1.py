#!/usr/bin/python3.4

import sys
import math

# not more than c coins of d
# v maximum value

def repdiv(v, d, nb):
    for i in range(nb):
        v//=d
    return v

def nb_words(s, word):
    pos = 0
    nb = 0
    while True:
        pos = s.find(word, pos)
        if pos == -1:
            return nb
        pos = pos + 1
        nb = nb + 1

def solve(k, l, s, keys, word):
    prob = 0.
    max_bananas = 0.

    #Small

    total = 0

    for val in range(k ** s):
        word_typed = ''.join([keys[repdiv(val, k, i) % k] for i in range(s)])
        nb = nb_words(word_typed, word)

        max_bananas = max(max_bananas, nb)
        total += nb

    return max_bananas - (float(total) / float(k ** s))

def main():
    nb = int(get_line())
    for case_id in range(1, nb + 1):
        k, l, s = [int(a) for a in get_line().split()]
        keys = get_line()
        word = get_line()

        ret = solve(k, l, s, keys, word)

        print('Case #%d: %s' % (case_id, ret), file = o)

def get_line():
    return f.readline().strip()

def open_files():
    if len(sys.argv) == 1:
        f = sys.stdin
        o = sys.stdout

    if len(sys.argv) == 2:
        f = open(sys.argv[1], 'r')
        o = sys.stdout

    if len(sys.argv) == 3:
        f = open(sys.argv[1], 'r')
        o = open(sys.argv[2], 'w')

    return (f, o)

if __name__ == "__main__":
    (f, o) = open_files()
    main()

