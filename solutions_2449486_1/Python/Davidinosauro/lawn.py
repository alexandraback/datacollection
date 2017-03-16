#!python

import sys


def result(tb):
    rows_max = [max(r) for r in tb]
    #print('max_row:', str(max_in_row))
    cols_max = [max(c) for c in zip(*tb)]
    #print('max_col:', str(max_in_col))
    for i in range(len(rows_max)):
        for j in range(len(cols_max)):
            x = tb[i][j]
            if x != rows_max[i] and x != cols_max[j]:
                return 'NO'
    return 'YES'


if __name__ == '__main__':
    sys.stdin.readline()
    t = 0
    while True:
        t += 1
        try:
            raws = int(sys.stdin.readline().strip().split(' ')[0])
        except ValueError:
            break
        tb = [[int(x) for x in sys.stdin.readline().strip().split()] for i in range(raws)]

        print("Case #{}: {}".format(str(t), result(tb)))
