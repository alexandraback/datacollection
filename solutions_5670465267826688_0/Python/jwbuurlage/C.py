#!/usr/bin/python3
from enum import Enum

mult = {
    '11': '1',
    'i1': 'i',
    'j1': 'j',
    'k1': 'k',
    '1i': 'i',
    'ii': '-1',
    'ji': '-k',
    'ki': 'j',
    '1j': 'j',
    'ij': 'k',
    'jj': '-1',
    'kj': '-i',
    '1k': 'k',
    'ik': '-j',
    'jk': 'i',
    'kk': '-1'
}
    
line = input()
T = int(line)

for run in range(1, T + 1):
    line = input()
    L, X = map(int, line.split(' '))

    line = input()
    LX = line * X

    search = 'i'
    sign = 1
    current = '1'
    for c in LX:
        current = mult[current + c]

        if current[0] is '-':
            sign *= -1
            current = current[1:]

        if search is 'i' and current is 'i' and sign is 1:
            search = 'j'
            current = '1'
        elif search is 'j' and current is 'j' and sign is 1:
            search = 'k'
            current = '1'

    if search is 'k' and current is 'k' and sign is 1:
        print("Case #%i: %s" % (run, 'YES'))
    else:
        print("Case #%i: %s" % (run, 'NO'))
