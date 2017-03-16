import sys

import re


def run(filename):
    lines = open(filename + ".in").read().split("\n")[1:]  # remove the T
    fout = open(filename + ".out", "w")
    for t, line in enumerate(lines):
        result = equalize(*(line.split()))
        print("Case #{}: {}".format(t + 1, result, file=fout))
#        print("Case #{}: {}".format(t + 1, result))
    fout.close()

def equalize(c, d):
    cre = re.compile(c.replace("?", "."))
    dre = re.compile(d.replace("?", "."))
    best = (999, 0, 999)
    for i in range(10**len(c)):
        if cre.match(str(i).zfill(len(c))):
            for j in range(10**len(c)):
                if dre.match(str(j).zfill(len(c))):
                    best = min(best, (abs(j - i), i, j))
    return str(best[1]).zfill(len(c)) + " " + str(best[2]).zfill(len(c))

if __name__ == '__main__':
    run(sys.argv[1])
