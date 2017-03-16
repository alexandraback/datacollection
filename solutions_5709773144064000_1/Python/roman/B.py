#!/usr/bin/python2.7
import sys

if __name__ == "__main__":
    n = int(sys.stdin.readline())
    for tc in range(n):
        parts = sys.stdin.readline().split()
        rate = 2.0
        c = float(parts[0])
        f = float(parts[1])
        x = float(parts[2])
        elapsed = 0
        best_time = elapsed + x / rate
        while True:
            tm = elapsed + c / rate + x / (rate + f)
            if tm > best_time:
                break
            elapsed += c / rate
            rate += f
            best_time = elapsed + x / rate

        print "Case #" + str(tc + 1) + ":", best_time
