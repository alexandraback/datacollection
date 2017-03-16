import sys
import math

def rl():
    return sys.stdin.readline().strip()

def guess_gen(r, start=1, step=1):
    n = start
    while True:
        yield n, n * (2 * r + 2 * n - 1)
        n += step

def main():
    T = int(rl())
    for i in range(1, T+1):
        r, t = map(int, rl().split())
        for n, p in guess_gen(r, 1001, 1000):
            if p > t:
                for n2, p in guess_gen(r, n-1000, 1):
                    if p > t:
                        print 'Case #%d: %d' % (i, n2-1)
                        break
                break

if __name__ == '__main__':
    main()
