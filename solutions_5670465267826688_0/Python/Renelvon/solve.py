#!/usr/bin/env python3
import functools
import sys


_QUATERNION_MULT_TABLE = {
    ("1", "1"): "1",
    ("1", "i"): "i",
    ("1", "j"): "j",
    ("1", "k"): "k",

    ("i", "1"): "i",
    ("i", "i"): "-1",
    ("i", "j"): "k",
    ("i", "k"): "-j",

    ("j", "1"): "j",
    ("j", "i"): "-k",
    ("j", "j"): "-1",
    ("j", "k"): "i",

    ("k", "1"): "k",
    ("k", "i"): "j",
    ("k", "j"): "-i",
    ("k", "k"): "-1"
}


def main():
    input_file = sys.argv[1]
    solve(input_file)


def solve(input_file):
    with open(input_file) as f_in:
        testcases = int(next(f_in))
        for i in range(testcases):
            l, x = tuple(int(num) for num in next(f_in).split())
            spelling = next(f_in).rstrip()
            output = "YES" if can_be_written(spelling, l, x) else "NO"
            print("Case #%d: %s" % (i + 1, output))


def can_be_written(spelling, l, x):
    if l * x < 3:
        return False

    large_spelling = spelling * x
    iidx = find_minimal_i_prefix(large_spelling)  # position one past the end
    kidx = find_minimal_k_suffix(large_spelling)  # position at start

    if 0 <= iidx < kidx < l * x:
        return "j" == functools.reduce(
            mult_quarts, large_spelling[iidx:kidx], "1"
        )
    return False


def find_minimal_i_prefix(qtext):
    acc = "1"
    i, ltext = 0, len(qtext)
    while acc != "i" and i < ltext:
        acc = mult_quarts(acc, qtext[i])
        i += 1
    return i


def find_minimal_k_suffix(qtext):
    acc = "1"
    i = len(qtext)
    while acc != "k" and i > 0:
        i -= 1
        acc = mult_quarts(qtext[i], acc)
    return i


def mult_quarts(q1, q2):
    # Use only "-" sign, never "+"
    abs_val = _QUATERNION_MULT_TABLE[(q1[-1], q2[-1])]
    if (len(q1) + len(q2)) % 2 == 0:
        return abs_val
    elif len(abs_val) == 2:
        return abs_val[-1]
    else:
        return "-" + abs_val


if __name__ == '__main__':
    main()
