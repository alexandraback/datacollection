#!/usr/bin/env python3

from collections import Counter

#("ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE")
#  "SEVEN",, "NINE"
def solve(s):
    digits = [0] * 10
    c = Counter(s)
    digits[0] = c['Z']
    c.subtract(digits[0] * 'ZERO')
    digits[2] = c['W']
    c.subtract(digits[2] * 'TWO')
    digits[4] = c['U']
    c.subtract(digits[4] * 'FOUR')
    digits[6] = c['X']
    c.subtract(digits[6] * 'SIX')
    digits[8] = c['G']
    c.subtract(digits[8] * 'EIGHT')
    digits[1] = c['O']
    c.subtract(digits[1] * 'ONE')
    digits[3] = c['H']
    c.subtract(digits[3] * 'THREE')
    digits[5] = c['F']
    c.subtract(digits[5] * 'FIVE')
    digits[9] = c['I']
    c.subtract(digits[9] * 'NINE')
    digits[7] = c['S']

    num = []
    for i, d in enumerate(digits):
        if d:
            num.append(str(i) * d)
    return ''.join(num)


testcases = int(input())

for case_n in range(1, testcases+1):
    #case_data = map(int, input().split())
    case_data = input().split()
    print("Case #%i: %s" % (case_n, solve(*case_data)))
