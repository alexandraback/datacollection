import sys
import itertools
import numpy as np


def occurrences(string, target):
    if len(target) > 1 and target[0] == target[-1]:
        count = start = 0
        while True:
            start = string.find(target, start) + 1
            if start > 0:
                count += 1
            else:
                return count
    else:
        return string.count(target)


def solve(K, L, S, keyboard, target):
    target_set = set(target)
    keyboard_set = set(keyboard)
    #keyboard_prob = {key: keyboard.count(key)/float(len(keyboard)) for key in keyboard_set}
    if S < L:
        return 0.
    if not target_set.issubset(keyboard_set):
        return 0.
    if len(keyboard_set) == 1:
        return 0.

    total_combinations = max_bananas = payout = 0
    for combination in itertools.product(keyboard, repeat=S):
        total_combinations += 1
        bananas = occurrences(''.join(combination), target)
        payout += bananas
        if max_bananas < bananas:
            max_bananas = bananas
    return max_bananas - float(payout)/total_combinations


if __name__ == '__main__':
    filename_in = sys.argv[1]
    filename_out = filename_in.partition('.')[0] + '.out'
    with open(filename_out, "w") as fout:
        with open(filename_in, "r") as fin:
            T = int(fin.readline())
            for case in range(1, T+1):
                K, L, S = [int(x) for x in fin.readline().split()]
                keyboard = fin.readline().strip()
                target = fin.readline().strip()
                print >> fout, "Case #%i:" % case, solve(K, L, S, keyboard, target)
