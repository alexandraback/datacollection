import sys

def solve():
    a, b, k = map(int, sys.stdin.readline().split())
    total = 0
    for i in range(a):
        for j in range(b):
            if i & j < k:
                total += 1
    return total

if __name__ == '__main__':
    cases = int(sys.stdin.readline().split()[0])
    for i in range(cases):
        print('Case #%d: %d' % (i + 1, solve()))
