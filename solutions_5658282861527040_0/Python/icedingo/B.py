T = int(input())

for t in range(T):
    A, B, K = map(int, input().split())
    wins = 0
    for a in range(A):
        for b in range(B):
            if a&b < K:
                wins += 1

    print('Case #%d: %d' % (t+1, wins))
