# -*- coding: utf-8 -*-

import sys
from utools import files

def process(s):

    count = 0
    first_words = [w[0] for w in s]
    second_words = [w[1] for w in s]

    for first_word, second_word in zip(first_words, second_words):
        if first_words.count(first_word) >= 2 and second_words.count(second_word) >= 2:
            count += 1
    return count

def main(path):

    with open(path) as f:
        t = files.read_item(f, int)
        for i in range(1, t+1):
            n = files.read_item(f, int)
            s = []
            for _ in range(n):
                s.append(files.read_mutiple_items(f, tuple, str))
            result = process(s)
            print("Case #{}: {}".format(i, result))


if __name__ == "__main__":
    if len(sys.argv) < 2:
        print(sys.argv[0] + " <path_to_input_file>")
    else:
        main(sys.argv[1])
