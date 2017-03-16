#!/usr/bin/python

import sys

def main():
    data = sys.stdin.readlines()
    ntests = int(data.pop(0).strip())

    for testno in range(ntests):
        res = "YES"
        [nrows, ncols] = map(lambda x:int(x), data.pop(0).split(" "))
        rows = []
        cols = [[] for i in range(ncols)]
        for row in range(0,nrows):
            row = data.pop(0).strip().split(" ")
            row = map(lambda x:int(x), row)
            rows.append(row)
            for i, c in enumerate(row):
                cols[i].append(c)

        # solve
        try:
            for row in rows:
                M = max(row)
                for colno, elem in enumerate(row):
                    if elem < M:
                        if not elem == max(cols[colno]):
                            res = "NO"
                            raise ValueError
        except ValueError:
            pass
        # All rows are good !
        print("Case #%d: %s" % (testno + 1, res))

if __name__ == '__main__':
    main()
