#!/usr/bin/env python3.4
import sys
import math

def overlap_count(s):
    l = len(s)
    shift = l
    for i in range(1, l + 1):
        if s[i:] == s[:l - i]:
            shift = i
            break
    return shift

if __name__ == '__main__':
    for test_case in range(int(sys.stdin.readline())):
        sys.stdout.write('Case #{}: '.format(test_case + 1))
        keys, target_len, str_len = map(int, sys.stdin.readline().split())
        keyboard = sys.stdin.readline().strip()
        target = sys.stdin.readline().strip()
        if not set(target).issubset(set(keyboard)):
            print(0.)
            continue
        shift = overlap_count(target)
        max_bananas = (str_len - target_len) // shift + 1
        # print(max_bananas)
        keyboard_dict = dict()
        for i in keyboard:
            keyboard_dict[i] = keyboard_dict.setdefault(i, 0) + 1
        for i in keyboard_dict:
            keyboard_dict[i] /= keys
        # print(keyboard_dict)
        prob = []
        for i in range(target_len):
            prob.append([0] * str_len)
        for i in range(str_len):
            prob[0][i] = keyboard_dict[target[0]]
        for i in range(1, target_len):
            for j in range(1, str_len):
                prob[i][j] = prob[i - 1][j - 1] * keyboard_dict[target[i]]
        print(max_bananas - sum(prob[target_len - 1]))

