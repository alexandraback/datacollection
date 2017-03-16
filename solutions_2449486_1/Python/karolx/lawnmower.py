__author__ = 'karol'

import sys
import numpy


def solve(lawn):
    max_rows = [max(row) for row in lawn]
    max_columns = [max(column) for column in lawn.T]
    it = numpy.nditer(lawn, flags=['multi_index'])
    while not it.finished:
        if it[0] != max_rows[it.multi_index[0]] and it[0] != max_columns[it.multi_index[1]]:
            return "NO"
        it.iternext()
    return "YES"


def main():
    T = int(sys.stdin.readline())
    for case in xrange(1, T + 1):
        N, M = (int(val) for val in sys.stdin.readline().split())
        lawn_list = list(
            [int(val) for val in sys.stdin.readline()[:-1].split()]
            for _ in xrange(N)
        )
        lawn = numpy.array(lawn_list)
        solution = solve(lawn)
        print "Case #%d: %s" % (case, solution)


main()