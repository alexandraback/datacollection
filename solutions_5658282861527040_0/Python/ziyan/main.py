import sys
import Queue

def process(A, B, K):
    count = 0
    for a in range(A):
        for b in range(B):
            if (a & b) < K:
                count += 1
    return count

def main():
    cases = int(sys.stdin.readline())

    for case in range(cases):
        A, B, K = map(long, sys.stdin.readline().strip().split())
        print 'Case #%d: %d' % (case + 1, process(A, B, K))

if __name__ == '__main__':
    main()
