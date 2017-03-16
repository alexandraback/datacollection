#!/usr/bin/env python3

import sys

table = str.maketrans("ynficwlbkuomxsevzpdrjghtaq", "abcdefghijklmnopqrstuvxwyz")

def translate(line):
    return line.translate(table)

if __name__ == "__main__":
    ncases = int(sys.stdin.readline().strip())
    for case in range(1, ncases + 1):
        line = sys.stdin.readline().strip()
        print("Case #", case, ": ", translate(line), sep="")
