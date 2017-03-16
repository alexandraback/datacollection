def naive(S):
    out = ''
    for c in S:
        out = max(c + out, out + c)
    return out

for x in range(1, int(input()) + 1):
    S = input().strip()
    print('Case #%d:' % x, naive(S))
