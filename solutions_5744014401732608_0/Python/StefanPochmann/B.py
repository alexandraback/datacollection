def naive(B, M):
    s = B * (B+1) // 2
    for mask in range(2**s):
        slides = ['0' * B] * B
        for j in range(B):
            for k in range(B-1 - j):
                slides[j] = slides[j][1:] + '01'[mask % 2]
                mask //= 2
        ways = [1]
        for j in range(1, B):
            ways.append(sum(ways[k] for k in range(j) if slides[k][j] == '1'))
        if ways[-1] == M:
            return slides

for x in range(1, int(input()) + 1):
    B, M = map(int, input().split())
    slides = naive(B, M)
    if slides:
        print('Case #%d: POSSIBLE' % x)
        for s in slides:
            print(s)
    else:
        print('Case #%d: IMPOSSIBLE' % x)
