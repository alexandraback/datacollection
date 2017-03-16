__author__ = 'nullard@gmail.com'

import os
import sys

def brute(d):
    d.sort(reverse=True)
    max_num = d[0]
    best = max_num
    for target in range(2, max_num + 1):
        steps = 0
        for diner in d:
            if diner > target and steps + target < best:
                steps += (diner - 1) / target
            else:
                break
        if steps + target < best:
            best = steps + target
    return best

def main():
    ifile = sys.stdin

    ofilename = 'test.out'

    if os.path.exists('B-large.in'):
        ifile = open('B-large.in')
        ofilename = 'B-large.out'
    elif os.path.exists('B-small.in'):
        ifile = open('B-small.in')
        ofilename = 'B-small.out'
    elif os.path.exists('B-sample.in'):
        ifile = open('B-sample.in')
        ofilename = 'B-sample.out'

    output = []

    cases = ifile.readline()
    for case in range(int(cases)):
        case_num = case + 1
        unused_diners = int(ifile.readline())
        pancakes = map(int, ifile.readline().split())
        pancakes.sort(reverse=True)
        strcakes = str(pancakes)
        result = str(brute(pancakes))

        output.append('Case #' + str(case_num) + ': ' + str(result))

    print ofilename
    ofile = open(ofilename, 'w')
    ofile.writelines('\n'.join(output))
    ofile.close()
    print '\n'.join(output)


if __name__ == '__main__':
    main()