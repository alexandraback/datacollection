# -*- coding: utf-8 -*-

import sys
from utools import files

# ZERO -> Z
# ONE -> O (after TWO)
# TWO -> W
# THREE -> H (after EIGHT)
# FOUR -> U
# FIVE -> F (after FOUR)
# SIX -> X
# SEVEN -> V (after FIVE)
# EIGHT -> G
# NINE

strings = ["ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"]

def process(s: str):
    digits = []
    while "Z" in s:
        digits.append(0)
        for c in "ZERO":
            s = s.replace(c, "", 1)
    while "W" in s:
        digits.append(2)
        for c in "TWO":
            s = s.replace(c, "", 1)
    while "X" in s:
        digits.append(6)
        for c in "SIX":
            s = s.replace(c, "", 1)
    while "G" in s:
        digits.append(8)
        for c in "EIGHT":
            s = s.replace(c, "", 1)
    while "U" in s:
        digits.append(4)
        for c in "FOUR":
            s = s.replace(c, "", 1)
    while "F" in s:
        digits.append(5)
        for c in "FIVE":
            s = s.replace(c, "", 1)
    while "V" in s:
        digits.append(7)
        for c in "SEVEN":
            s = s.replace(c, "", 1)
    while "H" in s:
        digits.append(3)
        for c in "THREE":
            s = s.replace(c, "", 1)
    while "I" in s:
        digits.append(9)
        for c in "NINE":
            s = s.replace(c, "", 1)
    while "O" in s:
        digits.append(1)
        for c in "ONE":
            s = s.replace(c, "", 1)
    assert s == ""
    return "".join(map(str, sorted(digits)))

def main(path):

    with open(path) as f:
        t = files.read_item(f, int)
        for i in range(1, t+1):
            s = files.read_item(f, str)
            result = process(s)
            print("Case #{}: {}".format(i, result))


if __name__ == "__main__":
    if len(sys.argv) < 2:
        print(sys.argv[0] + " <path_to_input_file>")
    else:
        main(sys.argv[1])
