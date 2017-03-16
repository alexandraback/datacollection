import sys
import math
import os


def nex(t=int):
    return t(sys.stdin.readline().strip())


def mult(x, y):
    if x < 0:
        return -mult(-x, y)
    if y < 0:
        return -mul(x, -y)

    mat = [
        [0, 0, 0, 0, 0],
        [0, 1,  2,  3,  4],
        [0, 2, -1,  4, -3],
        [0, 3, -4, -1,  2],
        [0, 4,  3, -2, -1]
    ]

    return mat[x][y]


def letton(x):
    return {'1': 1, 'i': 2, 'j':3, 'k':4}[x]



def solve(k, s):
    s = s * k
    s = [letton(c) for c in s]

    cur0 = 1
    idx0 = 0
    n = len(s)
    # if n < 20:
        # print 's=%s' % s
    while cur0 != 2 and idx0 < n-2:
        cur0 = mult(cur0, s[idx0])
        idx0 += 1

    if cur0 != 2:
        return 'NO'

    # print 'idx0=%s' % idx0


    cur1 = 1
    idx1 = idx0
    while cur1 != 3 and idx1 < n-1:
        cur1 = mult(cur1, s[idx1])
        idx1 += 1

    if cur1 != 3:
        return 'NO'

    # print 'idx1=%s' % idx1

    idx2 = idx1
    cur2 = 1
    while idx2 < n:
        cur2 = mult(cur2, s[idx2])
        idx2 += 1

    # print 'cur2=%s' % cur2

    if cur2 != 4:
        return 'NO'
    return 'YES'



def main():
    t = nex()
    for case in range(1, t + 1):
        ans = "---"
        n, k = sys.stdin.readline().split()
        n = int(n)
        k = int(k)
        s = sys.stdin.readline().strip()

        ans = solve(k, s)
        sys.stdout.write('Case #%s: %s\n' % (case, ans))


if __name__ == '__main__':
    main()
