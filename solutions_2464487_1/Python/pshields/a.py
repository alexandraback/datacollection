import math
import sys


# def integer_sqrt(n):


def max_rings(r, t):
    return int(math.floor((math.sqrt(4 * (r * r - r) + 8 * t + 1) - 2 * r + 1) / 4))
    

if __name__ == '__main__':
    T = int(sys.stdin.readline())
    for z in range(1, T + 1):
        r, t = [int(x) for x in sys.stdin.readline().split()]
        result = max_rings(r, t)
        print("Case #%d: %d" % (z, max(1, result)))
