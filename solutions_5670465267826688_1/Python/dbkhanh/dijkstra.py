#!/usr/bin/env python

import os, sys

class Quaternion(object):

    mult_table = {
        ("1", "1") : "1",
        ("1", "i") : "i",
        ("1", "j") : "j",
        ("1", "k") : "k",
        ("i", "1") : "i",
        ("i", "i") : "-1",
        ("i", "j") : "k",
        ("i", "k") : "-j",
        ("j", "1") : "j",
        ("j", "i") : "-k",
        ("j", "j") : "-1",
        ("j", "k") : "i",
        ("k", "1") : "k",
        ("k", "i") : "j",
        ("k", "j") : "-i",
        ("k", "k") : "-1"
        }

    def __init__(self, x):
        if x in ["i", "j", "k", "-i", "-j", "-k", "1", "-1"]:
            self.x = x
        else:
            raise ValueError("invalid quaternion: {}".format(x))

    def is_neg(self):
        return self.x.startswith("-")

    def _abs(self):
        if self.is_neg():
            return self.x[1:]
        else:
            return self.x

    def mult(self, y):
        assert isinstance(y, Quaternion)
        negate = self.is_neg() != y.is_neg()
        abs_x = self._abs()
        abs_y = y._abs()
        prod = Quaternion(Quaternion.mult_table[(abs_x, abs_y)])
        if negate:
            if prod.is_neg():
                prod.x = prod._abs()
            else:
                prod.x = "-" + prod.x
        return prod

    @staticmethod
    def simplify(word):
        prod = Quaternion("1")
        for c in word:
            prod = prod.mult(Quaternion(c))
        return prod

    @staticmethod
    def find_from_left(word, target):
        prod = Quaternion("1")
        for i in xrange(len(word)):
            prod = prod.mult(Quaternion(word[i]))
            if prod == target:
                return i+1
        return None

    @staticmethod
    def find_from_right(word, target):
        prod = Quaternion("1")
        for i in xrange(len(word)-1, -1, -1):
            prod = Quaternion(word[i]).mult(prod)
            if prod == target:
                return i
        return None

    def __str__(self):
        return self.x

    def __eq__(self, other):
        return self.x == other.x

    def __ne__(self, other):
        return self.x != other.x

def solve(word, power):
    if power > 8:
        power = 8 + (power - 8) % 4
    word = word * power
    middle_start = Quaternion.find_from_left(word, Quaternion("i"))
    middle_end = Quaternion.find_from_right(word, Quaternion("k"))
    if middle_start is None or middle_end is None:
        return "NO"
    middle_word = word[middle_start:middle_end]
    middle = Quaternion.simplify(word[middle_start:middle_end])
    if middle != Quaternion("j"):
        return "NO"
    return "YES"

def main():
    lines = open(sys.argv[1]).read().rstrip().splitlines()
    N = int(lines[0])
    for case in range(1, N+1):
        word = lines[2*case]
        power = int(lines[2*case-1].split()[1])
        answer = solve(word, power)
        print("Case #{}: {}".format(case, answer))

if __name__ == "__main__":
    main()
