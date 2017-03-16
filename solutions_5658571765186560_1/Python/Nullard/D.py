__author__ = 'nullard@gmail.com'

import os
import sys


def main():
    ifile = sys.stdin

    ofilename = 'test.out'

    if os.path.exists('D-large.in'):
        ifile = open('D-large.in')
        ofilename = 'D-large.out'
    elif os.path.exists('D-small.in'):
        ifile = open('D-small.in')
        ofilename = 'D-small.out'
    elif os.path.exists('D-sample.in'):
        ifile = open('D-sample.in')
        ofilename = 'D-sample.out'

    output = []

    cases = int(ifile.readline())
    for case in range(cases):
        case_num = case + 1
        result = None

        x, r, c = map(int, ifile.readline().split())

        if (r * c) % x != 0: result = 'RICHARD'
        elif x == 2: result = 'GABRIEL'
        elif min(r, c) <= (x / 2): result = 'RICHARD'
        elif x >= 7: result = 'RICHARD'
        else: result = 'GABRIEL'

        output.append('Case #' + str(case_num) + ': ' + result)

    ofile = open(ofilename, 'w')
    ofile.writelines('\n'.join(output))
    ofile.close()
    print '\n'.join(output)


if __name__ == '__main__':
    main()