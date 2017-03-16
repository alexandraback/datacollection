#!/usr/bin/env python

import sys

def main():
    input = sys.stdin
    T = int(input.readline())
    for t in range(T):
        A, B = map(int, input.readline().split())

        power = 1
        while power * 10 <= A:
            power *= 10

        num = 0
        for N in range(A, B + 1):
            shift = (N % 10) * power + (N / 10)
            while shift != N:
                if A <= shift <= B and shift < N:
                    num += 1
                shift = (shift % 10) * power + (shift / 10)

        print "Case #%d: %s" % (t + 1, num)

    return 0

if __name__ == "__main__":
    main()
