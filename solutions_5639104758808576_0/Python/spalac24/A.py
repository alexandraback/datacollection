import sys
import math
import os


def main():
    t = int(raw_input())
    for case in range(1, t + 1):
        sm, s = sys.stdin.readline().split()
        acum = int(s[0])
        ans = 0
        for idx, c in enumerate(s[1:], 1):
            c = int(c)
            toadd = 0
            if c and acum < idx:
                toadd = idx - acum
            acum += c + toadd
            ans += toadd
            # print '%s %s %s %s' % (idx, c, acum, ans)
        sys.stdout.write('Case #%s: %s\n' % (case, ans))


if __name__ == '__main__':
    main()
