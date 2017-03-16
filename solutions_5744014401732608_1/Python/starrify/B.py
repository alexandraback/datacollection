# coding: utf8

import sys


def main():
    max_possible = [0, 0]
    for i in range(2, 50 + 1):
        max_possible.append(1 + sum(max_possible))
    t = int(sys.stdin.readline())
    for _t in range(t):
        b, m = [int(x) for x in sys.stdin.readline().strip().split()]
        if max_possible[b] < m:
            print('Case #%s: %s' % (_t + 1, 'IMPOSSIBLE'))
        else:
            print('Case #%s: %s' % (_t + 1, 'POSSIBLE'))
            target = None
            for i in range(51):
                if max_possible[i] >= m:
                    target = i - 1
                    break
            mbin = bin(m).split('b')[1]
            if mbin.count('1') == 1:
                mbin = mbin.replace('0', '1')
            else:
                mbin = mbin + '0'
            mbin = '0' * b + mbin
            # first lines
            for i in range(1, b):
                print '0' * i + '1' * (b - i - 1) + mbin[0 - i]
            # last line
            print '0' * b


if __name__ == '__main__':
    main()
