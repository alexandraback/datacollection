def solve():
    A, B, K = map(long, raw_input().split())
    K = K - 1
    
    total = 0
    for i in range(A):
        for j in range(B):
            if (i & j) <= K:
                total += 1
    print total

if __name__ == "__main__":
    T = input()
    for i in range(T):
        print "Case #%d:" % (i+1),
        solve()