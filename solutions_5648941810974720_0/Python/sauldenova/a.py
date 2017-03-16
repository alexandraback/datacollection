#!/usr/local/bin/python3

from __future__ import print_function

def letter_value(letter):
    return ord(letter) - ord('A');

T = int(input())
for t in range(1, T + 1):
    print('Case #', t, ': ', sep= '', end='')
    line = str(input()).strip()
    array = [0 for i in range(26)]
    for c in line:
        array[letter_value(c)] += 1
    result = []

    result += [0 for i in range(array[letter_value('Z')])]

    array[letter_value('E')] -= array[letter_value('Z')];
    array[letter_value('R')] -= array[letter_value('Z')];
    array[letter_value('O')] -= array[letter_value('Z')];
    array[letter_value('Z')] -= array[letter_value('Z')];

    result += [2 for i in range(array[letter_value('W')])]

    array[letter_value('T')] -= array[letter_value('W')];
    array[letter_value('O')] -= array[letter_value('W')];
    array[letter_value('W')] -= array[letter_value('W')];

    result += [8 for i in range(array[letter_value('G')])]

    array[letter_value('E')] -= array[letter_value('G')];
    array[letter_value('I')] -= array[letter_value('G')];
    array[letter_value('H')] -= array[letter_value('G')];
    array[letter_value('T')] -= array[letter_value('G')];
    array[letter_value('G')] -= array[letter_value('G')];

    result += [6 for i in range(array[letter_value('X')])]

    array[letter_value('I')] -= array[letter_value('X')];
    array[letter_value('S')] -= array[letter_value('X')];
    array[letter_value('X')] -= array[letter_value('X')];

    result += [7 for i in range(array[letter_value('S')])]

    array[letter_value('E')] -= array[letter_value('S')];
    array[letter_value('E')] -= array[letter_value('S')];
    array[letter_value('N')] -= array[letter_value('S')];
    array[letter_value('V')] -= array[letter_value('S')];
    array[letter_value('S')] -= array[letter_value('S')];

    result += [5 for i in range(array[letter_value('V')])]

    array[letter_value('F')] -= array[letter_value('V')];
    array[letter_value('I')] -= array[letter_value('V')];
    array[letter_value('E')] -= array[letter_value('V')];
    array[letter_value('V')] -= array[letter_value('V')];

    result += [4 for i in range(array[letter_value('F')])]

    array[letter_value('O')] -= array[letter_value('F')];
    array[letter_value('U')] -= array[letter_value('F')];
    array[letter_value('R')] -= array[letter_value('F')];
    array[letter_value('F')] -= array[letter_value('F')];

    result += [9 for i in range(array[letter_value('I')])]

    array[letter_value('N')] -= array[letter_value('I')];
    array[letter_value('N')] -= array[letter_value('I')];
    array[letter_value('E')] -= array[letter_value('I')];
    array[letter_value('I')] -= array[letter_value('I')];

    result += [3 for i in range(array[letter_value('H')])]

    array[letter_value('T')] -= array[letter_value('H')];
    array[letter_value('R')] -= array[letter_value('H')];
    array[letter_value('E')] -= array[letter_value('H')];
    array[letter_value('E')] -= array[letter_value('H')];
    array[letter_value('H')] -= array[letter_value('H')];

    result += [1 for i in range(array[letter_value('E')])]

    array[letter_value('O')] -= array[letter_value('E')];
    array[letter_value('N')] -= array[letter_value('E')];
    array[letter_value('E')] -= array[letter_value('E')];

    result = sorted(result)

    for i in result:
        print(i, sep='', end='')
    print()
