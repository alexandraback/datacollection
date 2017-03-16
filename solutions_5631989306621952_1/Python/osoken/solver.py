# coding: UTF-8

import sys


def solve(x):
    ran = ''
    for l in x:
        if len(ran) == 0:
            ran = l
        else:
            if l < ran[0]:
                ran = ran + l
            else:
                ran = l + ran
    return ran


if __name__ == '__main__':
    problemCounts = int(sys.stdin.readline())
    for cn, prob in enumerate(sys.stdin.readlines()):
        sys.stdout.write('Case #%d: %s\n' % ((cn+1), solve(prob.strip())))
