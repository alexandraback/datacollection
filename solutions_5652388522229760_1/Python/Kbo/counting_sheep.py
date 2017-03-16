# -*- coding: utf-8 -*-

import sys


def process(n):

    if n == 0:
        return "INSOMNIA"

    already_seen_digits = set()
    factor = 1
    resulting_n = n * factor
    debug = False

    while True:
        already_seen_digits = already_seen_digits.union([int(i) for i in str(resulting_n)])
        if len(already_seen_digits) == 10:
            return resulting_n
        factor += 1
        resulting_n = n * factor

        if debug:
            return "INSOMNIA"


def main(path):

    with open(path) as f:
        content = f.readlines()
    t = int(content[0].replace("\n", ""))
    for i in range(1, t+1):
        number = int(content[i].replace("\n", ""))
        result = process(number)
        print("Case #{}: {}".format(i, result))


# def main(path):
#
#     # with open(path) as f:
#     #     content = f.readlines()
#     # t = int(content[0].replace("\n", ""))
#     for i in range(0, 10**6):
#         result = process(i)
#         print("Case #{}: {}".format(i, result))



if __name__ == "__main__":
    if len(sys.argv) < 2:
        print(sys.argv[0] + " <path_to_input_file>")
    else:
        main(sys.argv[1])
