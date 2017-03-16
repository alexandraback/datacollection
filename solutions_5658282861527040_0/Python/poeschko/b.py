import sys

def solve(A, B, K):
    count = 0
    for a in range(A):
        for b in range(B):
            if a & b < K:
                count += 1
    return count

def main():
    T = int(sys.stdin.readline())
    for t in range(T):
        A, B, K = map(int, sys.stdin.readline().split())
        result = solve(A, B, K)
        print "Case #%d: %s" % (t + 1, result)

if __name__ == '__main__':
    main()
