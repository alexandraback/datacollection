# -*- coding: utf-8 -*-

import sys


def process(s):
    res = s[0]
    for c in s[1:]:
        if c >= res[0]:
            res = c + res
        else:
            res = res + c
    return res


def main(path):

    with open(path) as f:
        content = f.readlines()
    t = int(content[0].replace("\n", ""))
    for i in range(1, t+1):
        s = content[i].replace("\n", "")
        result = process(s)
        print("Case #{}: {}".format(i, result))


if __name__ == "__main__":
    if len(sys.argv) < 2:
        print(sys.argv[0] + " <path_to_input_file>")
    else:
        main(sys.argv[1])
