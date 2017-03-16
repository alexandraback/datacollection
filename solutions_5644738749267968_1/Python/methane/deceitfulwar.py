from __future__ import print_function
import sys
import bisect


def war(ws1, ws2):
    point = 0
    while ws1:
        w = ws1.pop()
        if w > ws2[-1]:
            point += 1
            del ws2[0]
        else:
            i = bisect.bisect(ws2, w)
            del ws2[i]
    return point


def deceitfulwar(ws1, ws2):
    point = 0
    for w in ws1:
        if w > ws2[0]:
            point += 1
            del ws2[0]
        else:
            del ws2[-1]
    return point


def main():
    T = int(sys.stdin.readline())

    for t in range(1, T+1):
        n = int(sys.stdin.readline())
        ws1 = map(float, sys.stdin.readline().split())
        ws1.sort()
        ws2 = map(float, sys.stdin.readline().split())
        ws2.sort()
        print("Case #{}: {} {}".format(
            t, deceitfulwar(ws1[:], ws2[:]), war(ws1[:], ws2[:])))

main()
