# -*- coding: utf-8 -*-

import sys


def process(k, c, s):

    assert k == s  # small input
    coef = k ** (c-1)
    return " ".join([str(1 + coef * x) for x in range(k)])


def main(path):
    with open(path) as f:
        content = f.readlines()
    t = int(content[0].replace("\n", ""))
    for i in range(1, t + 1):
        k, c, s = (int(x) for x in content[i].replace("\n", "").split(" "))
        result = process(k, c, s)
        print("Case #{}: {}".format(i, result))


if __name__ == "__main__":
    if len(sys.argv) < 2:
        print(sys.argv[0] + " <path_to_input_file>")
    else:
        main(sys.argv[1])