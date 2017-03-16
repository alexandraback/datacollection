#!/usr/bin/env python
# -*- coding: utf-8 -*-

def solve(prob_num, content):
    name, n = content[0].split(' ')
    n = int(n)
    name_length = len(name)
    n_value = 0
    VOWEL = 'aeiou'

    for i in xrange(name_length - n + 1):
        for j in xrange(i + n, name_length + 1):
            num_consecutive_consonant = 0
            for c in name[i:j]:
                if c not in VOWEL:
                    num_consecutive_consonant += 1
                else:
                    num_consecutive_consonant = 0

                if num_consecutive_consonant == n:
                    n_value += 1
                    break

    return 'Case #{order}: {n_value}'.format(order=prob_num, n_value=n_value)

def main():
    content = []
    lines_per_case = 1

    T = int(raw_input())

    for i in xrange(T * lines_per_case):
        content.append(raw_input())

    for i in xrange(T):
        print(solve(i + 1, content[i*lines_per_case:(i+1)*lines_per_case]))

if __name__ == '__main__':
    main()
