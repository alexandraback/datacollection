import sys
import math

multiplication = {
    '1': {
        '1': (1, '1'),
        'i': (1, 'i'),
        'j': (1, 'j'),
        'k': (1, 'k')
    },
    'i': {
        '1': (1, 'i'),
        'i': (-1, '1'),
        'j': (1, 'k'),
        'k': (-1, 'j')
    },
    'j': {
        '1': (1, 'j'),
        'i': (-1, 'k'),
        'j': (-1, '1'),
        'k': (1, 'i')
    },
    'k': {
        '1': (1, 'k'),
        'i': (1, 'j'),
        'j': (-1, 'i'),
        'k': (-1, '1')
    }
}


def multiply(number, l):
    sign, sym = multiplication[number[1]][l]
    return (number[0] * sign, sym)


def find(s, index, ijk, max_length):
    length = len(s)
    value = (1, '1')

    while index < max_length:
        value = multiply(value, s[index % length])
        index += 1
        if value == (1, ijk): break

    return index


def solve(repeat, s):
    length = len(s)
    four_length = 4 * length

    index = find(s, 0, 'i', four_length)
    if four_length == index: return 'NO'

    index = find(s, index, 'j', four_length * 2)
    if four_length * 2 == index: return 'NO'

    index = find(s, index, 'k', four_length * 3)
    if four_length * 3 == index: return 'NO'

    if repeat <= (index - 1) // length: return 'NO'

    value = (1, '1')
    remaining = (repeat - 1 - (index - 1) // length) % 4
    while index % length != 0:
        value = multiply(value, s[index % length])
        index += 1
    for i in range(remaining * length):
        value = multiply(value, s[index % length])
        index += 1

    return 'YES' if value == (1, '1') else 'NO'


if __name__ == "__main__":
    testcases = int(input())

    for caseNr in range(1, testcases + 1):
        L, X = [int(x) for x in input().split(' ')]
        S = input()
        print("Case #%i: %s" % (caseNr, solve(X, S)))