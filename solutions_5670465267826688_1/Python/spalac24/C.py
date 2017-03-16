import sys
import math
import os


def nex(t=int):
    return t(sys.stdin.readline().strip())


def mult(x, y):
    if x < 0:
        return -mult(-x, y)
    if y < 0:
        return -mult(x, -y)

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


def gets(s, i):
    return s[i % (len(s))]



def solve(k, s):
    s = [letton(c) for c in s]

    cur0 = 1
    idx0 = 0
    ls = len(s)
    n = ls * k
    # if n < 20:
    #     print 's=%s' % s

    # print gets(s, 0), gets(s, 1), gets(s, 2)

    known_states = set([])
    while cur0 != 2 and idx0 < n-2:
        cur0 = mult(cur0, gets(s, idx0))
        idx0 += 1

        if (cur0, idx0 % ls) in known_states:
            return 'NO'

        known_states.add((cur0, idx0 % ls))
        # print 'cur0=%s' % cur0

    if cur0 != 2:
        return 'NO'

    # print 'idx0=%s' % idx0


    cur1 = 1
    idx1 = idx0
    known_states = set([])
    while cur1 != 3 and idx1 < n-1:
        cur1 = mult(cur1, gets(s, idx1))
        idx1 += 1

        if (cur1, idx1 % ls) in known_states:
            return 'NO'
        # print 'cur1=%s' % cur1
        known_states.add((cur1, idx1 % ls))


    if cur1 != 3:
        return 'NO'

    # print 'idx1=%s' % idx1

    # premultiply whole string

    cur3 = 1
    for c in s:
        cur3 = mult(cur3, c)

    idx2 = idx1
    cur2 = 1
    # print 'idx2=%s' % idx2
    # print 'cur3=%s' % cur3

    while idx2 % ls:
        cur2 = mult(cur2, gets(s, idx2))
        idx2 += 1
        # print 'cur2=%s' % cur2

    for _ in range(((n - idx2) / ls) % 4):
        cur2 = mult(cur2, cur3)
        # print 'cur2=%s*' % cur2

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
