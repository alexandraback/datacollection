#!/usr/bin/env python
import math


def print_result(case_no, msg):
    print "Case #%d: %s" % (case_no, msg)

vowel = {
    'a': 1,
    'e': 1, 
    'o': 1,
    'i': 1,
    'u': 1,
}

def run_case(case_no):
    name, n = raw_input().split(' ')
    n = int(n)
    in_vowel = False
    logs = []
    tmp = 0
    for i, c in enumerate(name):
        if c in vowel:
            if not in_vowel:
                logs.append((tmp, i))
            in_vowel = True
            continue
        if in_vowel:
            tmp = i
        in_vowel = False
    if not in_vowel:
        logs.append((tmp, len(name)))
    logs = [(x, y) for x, y in logs if y - x >= n]
    logs.reverse()
    result = 0
    for i in range(len(name)):
        if len(logs) == 0:
            break
        x, y = logs[-1]
        if i <= x:
            result += len(name) - x - n + 1
            continue
        if y - i >= n:
            result += len(name) - i - n + 1
            continue
        logs.pop()
        if len(logs) == 0:
            break
        x, y = logs[-1]
        if i <= x:
            result += len(name) - x - n + 1
            continue
        if y - i >= n:
            result += len(name) - i - n + 1
            continue
    print_result(case_no, str(result))

if __name__ == '__main__':
    num = int(raw_input())
    for i in xrange(num):
        run_case(i + 1)
