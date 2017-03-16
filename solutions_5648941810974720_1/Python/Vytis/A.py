#!/usr/bin/env python3

from collections import Counter

TEST = 'large'
IN = 'A-{}.in'.format(TEST)
OUT = 'A-{}.out'.format(TEST)


def run(s):
    cnt = dict(Counter(s))
    digits = []

    def add(word, digit, count):
        if not count:
            return
        for w in word:
            cnt[w] -= count
        digits.extend([digit] * count)

    add('ZERO', '0', cnt.get('Z', 0))
    add('TWO', '2', cnt.get('W', 0))
    add('FOUR', '4', cnt.get('U', 0))
    add('FIVE', '5', cnt.get('F', 0))
    add('SIX', '6', cnt.get('X', 0))
    add('SEVEN', '7', cnt.get('S', 0))
    add('EIGHT', '8', cnt.get('G', 0))
    add('NINE', '9', cnt.get('I', 0))
    add('ONE', '1', cnt.get('O', 0))
    add('THREE', '3', cnt.get('T', 0))

    digits.sort()
    return ''.join(digits)


def main():
    with open(IN) as fin, open(OUT, 'w') as fout:
        t = int(fin.readline().strip())
        for i in range(t):
            s = fin.readline().strip()
            res = run(s)
            print('Case #{}: {}'.format(i + 1, res), file=fout)


if __name__ == '__main__':
    main()
