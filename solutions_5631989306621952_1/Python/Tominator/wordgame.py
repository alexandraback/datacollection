#!/usr/bin/env python3

import sys

def best_word(word):
    result = [word[0]]

    for ch in word[1:]:
        if ch >= result[0]:
            result.insert(0, ch)
        else:
            result.append(ch)

    return "".join(result)

num_tests = int(sys.stdin.readline().strip())

for i in range(num_tests):
    word = sys.stdin.readline().strip()
    print("Case #%d: %s" % (i+1, best_word(word)))

