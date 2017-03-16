__author__ = 'michal'
import sys
import math


def lawnmower(rows, cols, lawn):

    rows_max_h = {}
    cols_max_h = {}


    for row in range(rows):
        max_h = 0

        for col in range(cols):
            h = lawn[(row, col)]
            if h > max_h:
                max_h = h

        rows_max_h[row] = max_h

    for col in range(cols):
        max_h = 0

        for row in range(rows):
            h = lawn[(row, col)]
            if h > max_h:
                max_h = h

        cols_max_h[col] = max_h

    for row in range(rows):
        for col in range(cols):
            h = lawn[(row, col)]

            if rows_max_h[row] > h and cols_max_h[col] > h:
                return 'NO'

    return 'YES'

if __name__=="__main__":

    file_out = None
    if len(sys.argv) >= 2:
        file = open(sys.argv[1])
        if len(sys.argv) == 3:
            file_out = open(sys.argv[2], 'w')
    else:
        file = sys.stdin

    cases = int(file.readline())

    for case in range(cases):

        line = file.readline()
        params = map(lambda x: int(x), line.split())

        rows = params[0]
        cols = params[1]

        lawn = {}

        for row in range(rows):
            line = file.readline()

            col = 0
            for h in line.strip().split():
                lawn[(row, col)] = int(h)
                col += 1

        result = lawnmower(rows, cols, lawn)

        out = "Case #%i: %s" % (case + 1, result)

        print out
        if file_out != None:
            file_out.write(out + '\n')



