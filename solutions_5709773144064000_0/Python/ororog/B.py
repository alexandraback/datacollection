import sys
from numpy import *


def main():
    T = input()
    for i in range(T): solve(i)


def solve(num):
    C, F, X =  map(float, raw_input().split())
    speed, time = 2.0, 0.0
    ans = 1.0e100
    while True:
        nans = time + X / speed
        if nans > ans: break
        ans = nans
        time += C / speed
        speed += F

    print 'Case #%d: %.10f' % (num + 1, ans)


if __name__ == '__main__':
    main()
