#!/usr/bin/env python

from string import maketrans

GOOGLERESE = maketrans(' acbedgfihkjmlonqpsrutwvyxz', ' yehosvcdxiulgkbzrntjwfpamq')

if __name__ == '__main__':
    with open('A-small-attempt0.in') as handle:
        lines = handle.readlines()
        for i, line in enumerate(lines[1:], start=1):
            print('Case #%s: %s' % (i, line.strip().translate(GOOGLERESE)))

