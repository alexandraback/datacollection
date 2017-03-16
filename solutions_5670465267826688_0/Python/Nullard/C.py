__author__ = 'nullard@gmail.com'

import os
import sys

ONE = 0
I = 1
J = 2
K = 3

class Quat(object):
    def __init__(self, value, neg):
        self.value = value
        self.neg = neg

    def __mul__(self, other):
        val = [[0, 1, 2, 3],
               [1, 0, 3, 2],
               [2, 3, 0, 1],
               [3, 2, 1, 0]]
        sign = [[1, 1, 1, 1],
                [1, -1, 1, -1],
                [1, -1, -1, 1],
                [1, 1, -1, -1]]
        return Quat(val[self.value][other.value], sign[self.value][other.value] * self.neg * other.neg)

    def __str__(self):
        letter = ['1', 'i', 'j', 'k'][self.value]
        if self.neg == -1:
            return '-' + letter
        else:
            return letter

def ij(s, count):
    # if count >= 8:
    #     big_s = s * 3
    # else:
    #     big_s = s * count
    big_s = s * count
    q1 = Quat(ONE, 1)
    target = 1
    #print s, big_s
    for pos, c in enumerate(big_s):
        q2 = Quat(ord(c) - ord('h'), 1)
        prod = q1 * q2
        #print q1, q2, prod
        if prod.value == target and prod.neg == 1:
            target += 1
            if target == 3:
                return True
            prod = Quat(ONE, 1)
        q1 = prod
    return False


def main():
    ifile = sys.stdin

    ofilename = 'test.out'

    if os.path.exists('C-large.in'):
        ifile = open('C-large.in')
        ofilename = 'C-large.out'
    elif os.path.exists('C-small.in'):
        ifile = open('C-small.in')
        ofilename = 'C-small.out'
    elif os.path.exists('C-sample.in'):
        ifile = open('C-sample.in')
        ofilename = 'C-sample.out'

    output = []

    cases = int(ifile.readline())
    for case in range(cases):
        case_num = case + 1
        result = None
        l, x = map(int, ifile.readline().split())
        s = ifile.readline().strip()
        q1 = Quat(ONE, 1)
        prod = q1
        for c in s:
            q2 = Quat(ord(c) - ord('h'), 1)
            prod = q1 * q2
            q1 = prod
        if ((prod.value == 0 and prod.neg == -1 and x % 2 == 1) or
            (prod.value > 0 and x % 4 == 2)):
            if ij(s, x):
                result = 'YES'
            else:
                result = 'NO'
        else:
            result = 'NO'

        output.append('Case #' + str(case_num) + ': ' + result)

    ofile = open(ofilename, 'w')
    ofile.writelines('\n'.join(output))
    ofile.close()
    print '\n'.join(output)


if __name__ == '__main__':
    main()