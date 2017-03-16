import sys
from math import *

def solve(n, lines):
    smallest_h = 9999999999
    smallest1 = None
    smallest2 = None
    for l in lines:
        if l[0] < smallest_h:
            smallest_h = l[0]
            smallest1 = l
        if l[0] == smallest_h:
            smallest2 = l

    rows = [0] * n
    cols = [0] * n

    print "s1", smallest1
    print "s2", smallest2
    f = [a for a in smallest1]
    f.extend(smallest2)
    f = list(set(f))
    f.sort()

    missing = 9999999

    for a in f:
        sw = []
        for l in lines:
            if l[0] == a:
                sw.append(l)
        if len(sw) == 0 or len(sw) > 2:
            # this is the missing line
            missing = a
            print "err 1", len(sw), a, f
            for l in lines:
                print l
            print ""
        elif len(sw) == 1:
            if a in smallest1:
                rows[smallest1.index(a)] = sw[0]
            else:
                cols[smallest2.index(a)] = sw[0]
        else:
            # try sw[0] row and sw[1] col
            flg = True
            if rows[smallest1.index(a)] == 0 or cols[smallest2.index(a)] == 0:
                flg = False
            for i in xrange(n):
                if not(cols[i] != 0 and cols[i][smallest1.index(a)] != sw[0][i]):
                    flg = False
                    break
                if not(rows[i] != 0 and rows[i][smallest2.index(a)] != sw[1][i]):
                    flg = False
                    break
            if flg:
                rows[smallest1.index(a)] = sw[0]
                cols[smallest2.index(a)] = sw[1]
            else:
                rows[smallest1.index(a)] = sw[1]
                cols[smallest2.index(a)] = sw[0]

    res = []
    for i in xrange(n):
        if rows[i] == 0:
            for j in xrange(n):
                res.append(str(cols[j][i]))
            return " ".join(res)
    for i in xrange(n):
        if cols[i] == 0:
            for j in xrange(n):
                res.append(str(rows[j][i]))
            return " ".join(res)
    print "error !!!"
    return 5

input_file = open(sys.argv[1], "r")
output_file = open(sys.argv[2], "w")

results = []
T = int(input_file.readline().strip())
for i in xrange(T):
    N = int(input_file.readline().strip())
    lines = []
    for j in xrange(2 * N - 1):
        row = [int(k.strip()) for k in input_file.readline().split()]
        lines.append(row)
    results.append(solve(N, lines))

for i in xrange(T):
    output_file.write("Case #{0}: {1}\n".format(i+1, results[i]))

input_file.close()
output_file.close()