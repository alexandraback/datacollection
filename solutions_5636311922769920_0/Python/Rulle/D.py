import sys
from math import ceil
sys.setrecursionlimit(200000)


def solve(K, C, S):
    checks = int(ceil(K / float(C)))
    if checks > S:
        return "IMPOSSIBLE"
    else:
        positions = []
        indexes = range(K)

        #print "We need",checks, "checks"
        for c in range(int(checks)):
            index = []
            for i in range(C):
                if indexes:
                    index.append(indexes.pop(0))
            #print "index", index
            # print index, i, K
            #print ([ i * K ** (j-1)  for i, j in  enumerate(index)])
            pos = int(sum([ j * K ** i  for i, j in  enumerate(index)]))
            #print pos
            positions.append(1+pos)
        assert not indexes


        return ' '.join(map(str, positions))


if __name__ == "__main__":
    f = open("D.in")

    lines = f.read().splitlines()
    interp_line = lambda x: map(int, x.split(" "))
    for idx, line in enumerate(lines[1:]):
        print "Case #%d: %s" % (1+idx, solve(*map(int, line.split())))

    f.close()
