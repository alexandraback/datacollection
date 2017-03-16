__author__ = 'nullard@gmail.com'

import os
import sys


def main():
    ifile = sys.stdin

    ofilename = 'test.out'

    if os.path.exists('A-large.in'):
        ifile = open('A-large.in')
        ofilename = 'A-large.out'
    elif os.path.exists('A-small.in'):
        ifile = open('A-small.in')
        ofilename = 'A-small.out'
    elif os.path.exists('A-sample.in'):
        ifile = open('A-sample.in')
        ofilename = 'A-sample.out'

    output = []

    cases = ifile.readline()
    for case in range(int(cases)):
        case_num = case + 1
        result = None

        target, shyness = ifile.readline().split()
        target = int(target)
        count = 0
        needed = 0
        for pos in range(target + 1):
            if count < pos:
                needed += 1
                count += 1
            count += int(shyness[pos])
            if count >= target:
                break
        result = needed
        output.append('Case #' + str(case_num) + ': ' + str(result))

    ofile = open(ofilename, 'w')
    ofile.writelines('\n'.join(output))
    ofile.close()
    print '\n'.join(output)

if __name__ == '__main__':
    main()