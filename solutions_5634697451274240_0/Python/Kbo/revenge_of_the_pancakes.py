# -*- coding: utf-8 -*-

import sys
from typing import List


def flip(stack: List[str]) -> List[str]:
    first_char = stack[0]
    replace_with = "+" if first_char == "-" else "-"
    i = 0
    stack_len = len(stack)
    while i < stack_len and stack[i] == first_char:
        stack[i] = replace_with
        i += 1
    return stack


def is_ok(stack: List[str]) -> bool:
    return "-" not in stack


def process(stack: List[str]) -> int:

    count = 0
    while not is_ok(stack):
        stack = flip(stack)
        count += 1
    return count


def main(path):
    with open(path) as f:
        content = f.readlines()
    t = int(content[0].replace("\n", ""))
    for i in range(1, t + 1):
        stack = list(content[i].replace("\n", ""))
        result = process(stack)
        print("Case #{}: {}".format(i, result))


if __name__ == "__main__":
    if len(sys.argv) < 2:
        print(sys.argv[0] + " <path_to_input_file>")
    else:
        main(sys.argv[1])
