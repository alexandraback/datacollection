__author__ = 'ligenjian'
import sys

sys.setrecursionlimit(1500)


def solve(l):
    max_pos = 0
    if len(l) == 0:
        return ''
    for idx, num in enumerate(l):
        if l[idx] >= l[max_pos]:
            max_pos = idx
    return l[max_pos] + solve(l[:max_pos]) + l[max_pos + 1:]


if __name__ == '__main__':
    input = open('input.txt', 'r')
    output = open('output.txt', 'w')
    t = int(input.readline())
    for i in range(t):
        s = input.readline().strip()
        print>>output,  'Case #%d: %s' % ((i + 1), solve(s))
