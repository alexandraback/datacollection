def solve(A, B, K):
    if A < K or B < K:
        return A * B

    ways = 0
    for a in range(A):
        for b in range(B):
            if a & b < K:
                ways += 1
    return ways

def main():
    T = int(input())
    for i in range(1, T + 1):
        A, B, K = (int(s) for s in input().strip().split())
        res = solve(A, B, K)
        print('Case #', i, ': ', res, sep='')

if __name__ == "__main__":
    main()
