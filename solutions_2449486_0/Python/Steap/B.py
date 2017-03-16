#!/usr/bin/python

import sys

def main():
    data = sys.stdin.readlines()
    ntests = int(data.pop(0).strip())

    for testno in range(ntests):
        res = "YES"
        [nrows, ncols] = map(lambda x:int(x), data.pop(0).split(" "))
        rows = []
        cols = ["" for i in range(ncols)]
        for row in range(0,nrows):
            row = data.pop(0).strip().replace(' ', '')
            rows.append(row)
            for i, c in enumerate(row):
                cols[i] += c

        # solve
        for row in rows:
            one_count = row.count('1')
            if one_count == ncols:
                # There are only 1s on this row.
                continue
            if one_count == 0:
                # There are only 2s on this row.
                continue
            # Mix of 1s and 2s...
            try:
                colno = -1
                while True:
                    colno = row.index('1', colno+1)
                    if cols[colno].count('1') < nrows:
                        res = "NO"
                        raise ValueError # HOHOHO
            except ValueError:
                pass

        # All rows are good !
        print("Case #%d: %s" % (testno + 1, res))
if __name__ == '__main__':
    main()
