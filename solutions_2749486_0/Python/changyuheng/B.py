#!/usr/bin/env python
# -*- coding: utf-8 -*-

LINES_PER_CASE = 1

def solve(prob_num, content):
    X, Y = map(int, content[0].split(' '))
    x, y = map(abs, [X, Y])
    steps = ''

    go_east = 'WE'
    go_west = 'EW'
    go_north = 'SN'
    go_south = 'NS'

    steps += go_east * x if X > 0 else go_west * x
    steps += go_north * y if Y > 0 else go_south * y

    return 'Case #{order}: {steps}'.format(order=prob_num, steps=steps)

def main():
    content = []
    T = int(raw_input())

    for i in xrange(T * LINES_PER_CASE):
        content.append(raw_input())

    for i in xrange(T):
        print(solve(i + 1, content[i*LINES_PER_CASE:(i+1)*LINES_PER_CASE]))

if __name__ == '__main__':
    main()
