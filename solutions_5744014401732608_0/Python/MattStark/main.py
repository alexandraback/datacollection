import sys
from string import ascii_uppercase

import math


class Jam(object):
    def __init__(self, filename):
        lines = open(filename + ".in").read().split("\n")[1:]  # remove the T
        fout = open(filename + ".out", "w")

        for t, line in enumerate(lines):
            result = self.solve(*map(int, (line.split())))
            print("Case #{}: {}".format(t + 1, result), file=fout)
    #        print("Case #{}: {}".format(t + 1, result))
        fout.close()

    def solve(self, b, m):
        need = math.ceil(math.log(m, 2)) + 2
        if need > b: return "IMPOSSIBLE"
        values = [[0] * (i + 1) + [1] * (need - i - 1) for i in range(need)]

        if m != 2**(need - 2):
            values[0][-1] = 0
            number = bin(m)[2:][::-1]
            for y, letter in enumerate(number):
                values[y + 1][-1] = int(letter)

        # fill in extra parts of the table we don't need
        if need < b:
            for y in range(b):
                if y < need:
                    values[y].extend([0] * (b - need))
                else:
                    values.append([0] * b)
            values[need - 1][b - 1] = 1

        ways = [1] + [0] * (b - 1)
        for y, row in enumerate(values):
            for x, val in enumerate(row):
                if val: ways[x] += ways[y]
        assert ways[-1] == m
        return "POSSIBLE\n" + "\n".join(''.join(map(str, line)) for line in values)

    def high(self):
        return max(range(len(self.parties)), key=self.parties.__getitem__)

if __name__ == '__main__':
    Jam(sys.argv[1])
