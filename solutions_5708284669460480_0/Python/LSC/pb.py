#!/usr/bin/env python3
import sys
import itertools

def main():
    T = int(sys.stdin.readline())
    for t in range(1, T+1):
        k, l, s = [int(x) for x in sys.stdin.readline().split()]
        sk = sys.stdin.readline().strip()
        sl = sys.stdin.readline().strip()
        ans = 0
        cnt = 0
        mx = 0
        for ss in itertools.product(sk, repeat=s):
            cnt += 1
            ss = ''.join(ss)
            cur = 0
            for off in range(s - l + 1):
                if ss[off:off+l] == sl:
                    cur += 1
            ans += cur
            if mx < cur: mx = cur
        ans = mx - ans / cnt
        print("Case #%s: %s" % (t, ans))


if __name__ == '__main__':
    main()
