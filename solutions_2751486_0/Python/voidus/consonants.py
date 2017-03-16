#!/usr/bin/env python3
# -*- coding:utf-8 -*-
import sys
import re

def is_good_word(word, n, L):
    limit = '{%d,%d}' % (n, L)
    pattern = '[bcdfghjklmnpqrstvwxyz]' + limit
    result = re.search(pattern, word)
    return result

def solve(name, n):
    L = len(name)
    words = []
    for i in range(n, L+1):
        words += [name[j:j+i] for j in range(L-i+1)]
    n_value = 0
    #import ipdb; ipdb.set_trace()
    for word in words:
        if is_good_word(word, n, L):
            n_value += 1
    return n_value

if __name__ == '__main__':
    inputdata = sys.stdin
    #inputdata = open('test.txt', 'rt')
    number = next(inputdata).rstrip()
    number = int(number)
    for case in range(number):
        line = next(inputdata)
        name, n = line.split(' ')
        n = int(n)
        result = solve(name, n)
        print('Case #{0}: {1}'.format(case+1, result))
