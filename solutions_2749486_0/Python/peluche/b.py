#!/usr/bin/env python2.7
#
# very naive version
# because in 1, 2, 3, 4, 5, ..., n, m
# m - n = 1


def solve(pos):
    res = ''
    x, y = pos
    if x >= 0:
        res += 'WE'*x
    else:
        res += 'EW'*(-x)
    if y >= 0:
        res += 'SN'*y
    else:
        res += 'NS'*(-y)

    return res

def main():
    T = int(raw_input())
    for i in range(0, T):
        pos = map(int, raw_input().split(' '))
        res = solve(pos)
        print 'Case #{}: {}'.format(i+1, res)

if __name__ == '__main__':
    main()
