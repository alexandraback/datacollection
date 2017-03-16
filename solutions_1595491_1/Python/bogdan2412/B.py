#!/usr/bin/env python

import sys

def main():
    input = sys.stdin
    T = int(input.readline())
    for t in range(T):
        ints = map(int, input.readline().split())
        N, S, p, sums = ints[0], ints[1], ints[2], ints[3:]

        # 3k   - k k   k   - k-1 k   k+1
        # 3k+1 - k k   k+1 - k-1 k+1 k+1
        # 3k+2 - k k+1 k+1 - k   k   k+2

        sums.sort(reverse=True)
        cnt = 0
        for sum in sums:
            normal_max = sum / 3
            if sum % 3 != 0:
                normal_max += 1

            if normal_max >= p:
                cnt += 1
                continue

            if sum <= 1:
                continue

            surprising_max = sum / 3 + 1
            if sum % 3 == 2:
                surprising_max += 1

            if surprising_max >= p and S > 0:
                cnt += 1
                S -= 1

        print "Case #%d: %s" % (t + 1, cnt)

    return 0

if __name__ == "__main__":
    main()
