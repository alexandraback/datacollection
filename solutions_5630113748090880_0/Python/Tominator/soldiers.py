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
for test in range(num_tests):
    num_rows = int(sys.stdin.readline().strip())
    Heights = set()

    for i in range(2 * num_rows - 1):
        line = sys.stdin.readline().strip()
        for s in line.split(" "):
            height = int(s.strip())
            if height in Heights:
                Heights.remove(height)
            else:
                Heights.add(height)

    print("Case #%d: %s" % (test+1, " ".join(str(x) for x in sorted(Heights))))

