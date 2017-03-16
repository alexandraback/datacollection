# -*- coding: utf-8 -*-
# python ProblemC.py < test3.in > C.small.out
# python ProblemC.py < A-small-attempt0.in > B.small.out
# =================================================================

result_out = ''

import heapq


result_dic = {('1', '1'): '1', ('1', 'i'): 'i', ('1', 'j'): 'j', ('1', 'k'): 'k',
              ('i', '1'): 'i', ('i', 'i'): '-1', ('i', 'j'): 'k', ('i', 'k'): '-j',
              ('j', '1'): 'j', ('j', 'i'): '-k', ('j', 'j'): '-1', ('j', 'k'): 'i',
              ('k', '1'): 'k', ('k', 'i'): 'j', ('k', 'j'): '-i', ('k', 'k'): '-1', }

def cross(x, y):
    return (('-' if (('-' in x) ^ ('-' in y)) else '') + result_dic[(x.replace('-', ''), y.replace('-', ''))]).replace(
        '--', '')


def search_i_j(repeat_time, L):
    idx_j = -1
    first_i = 0
    current = '1'
    for idx11 in xrange(first_i, len(L) * repeat_time+1):
        current = cross(current, L[idx11 % len(L)])
        if current == 'i':
            idx_j = idx11 + 1
            break
    if idx_j < 0:
        return 'NO'
    current = '1'
    for idx2 in xrange(idx_j, len(L) * repeat_time+1):
        current = cross(current, L[idx2 % len(L)])
        if current == 'j':
            return 'YES'
    return 'NO'


def check_L(X, L, L_tot):
    if L_tot == '1':
        return 'NO'
    if L_tot == '-1':
        if X % 2 == 0:
            return 'NO'
        repeat_time = min(X, 5)
        return search_i_j(repeat_time, L)

    if X % 2 == 0:
        if X % 4 == 0:
            return 'NO'
        repeat_time = min(X, 9)
        return search_i_j(repeat_time, L)
    else:
        return 'NO'


case_num = int(raw_input())
for idx in range(case_num):
    _, X = map(int, raw_input().split())
    data = raw_input()
    L = list(data)
    L_tot = '1'
    for i in range(0, len(L)):
        L_tot = cross(L_tot, L[i])

    case_out = check_L(X, L, L_tot)

    result_out += 'Case #%d: %s\n' % (idx + 1, case_out)
print result_out


