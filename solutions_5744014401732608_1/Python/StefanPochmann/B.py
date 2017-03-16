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

def smart(B, M):
    x = 2**(B-2)
    if M <= x:
        mask = 2*M if M < x else 2*(M-1)+1
        slides = ['0' * i + '1' * (B-1-i) + '01'[(mask >> (i-1)) % 2]
                  for i in range(1, B)] + ['0' * B]
        return slides

for x in range(1, int(input()) + 1):
    B, M = map(int, input().split())
    slides = smart(B, M)
    if slides:
        print('Case #%d: POSSIBLE' % x)
        for s in slides:
            print(s)
    else:
        print('Case #%d: IMPOSSIBLE' % x)
