#!/usr/bin/python2.7
import sys

if __name__ == "__main__":
    n = int(sys.stdin.readline())
    for tc in range(n):
        print "Case #" + str(tc + 1) + ":"
        parts = sys.stdin.readline().split()
        r = int(parts[0])
        c = int(parts[1])
        m = int(parts[2])
        n = r * c - m
        f = ['*' * c] * r
        f[0] = 'c' + f[0][1:]

        if r == 1:
            f = ['c' + '.' * (n - 1) + f[0][n:]]
        elif c == 1:
            f = ['c'] + ['.'] * (n - 1) + f[n:]
        elif n != 1:
            if n == 2 or n == 3 or n == 5 or n == 7 or ((r == 2 or c == 2) and n % 2 == 1):
                print "Impossible"
                continue
            rr = 2
            cc = 2
            while rr * cc + 1 < n:
                if rr < r and (rr <= cc or cc == c):
                    rr += 1
                else:
                    cc += 1
            f[0] = 'c' + '.' * (cc - 1) + f[0][cc:]
            for i in range(1, rr - 1):
                f[i] = '.' * cc + f[i][cc:]
            ccc = n - (rr - 1) * cc
            if ccc > cc:
                ccc -= 2
                if rr < r:
                    f[rr] = '..' + f[rr][2:]
                else:
                    f[0] = f[0][:cc] + '.' + f[0][cc + 1:]
                    f[1] = f[1][:cc] + '.' + f[1][cc + 1:]
            f[rr - 1] = '.' * ccc + f[r - 1][ccc:]

        for line in f:
            print line
