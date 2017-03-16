import sys
from collections import Counter
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

    def solve(self, jacket, pants, shirt, k):
        counts = Counter()
        results = []
        for j in range(1, 1+jacket):
            for p in range(1, 1+pants):
                for s in range(1, 1 + shirt):
                    if counts[("jp", j, p)] < k and counts[("js", j, s)] < k and counts[("ps", p, s)] < k:
                        counts[("jp", j, p)] += 1
                        counts[("js", j, s)] += 1
                        counts[("ps", p, s)] += 1
                        results.append("%d %d %d" % (j, p, s))

        return str(len(results)) + "\n" + "\n".join(results)


if __name__ == '__main__':
    Jam(sys.argv[1])
