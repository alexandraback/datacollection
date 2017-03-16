n = int(raw_input())

for i in range(n):
    (r, t) = map(int, raw_input().split())
    guessm = int((1 - 2 * r + (4 * r * r - 4 * r + 1 + 8 * t) ** 0.5) / 4.0)
    if ((guessm * 4) - 1 + 2 * r) ** 2 < (4 * r * r - 4 * r + 1 + 8 * t):
        while (((guessm + 1) * 4) - 1 + 2 * r) ** 2 <= (4 * r * r - 4 * r + 1 + 8 * t):
            guessm = guessm + 1
    elif ((guessm * 4) - 1 + 2 * r) ** 2 > (4 * r * r - 4 * r + 1 + 8 * t):
        while (((guessm)* 4) - 1 + 2 * r) ** 2 > (4 * r * r - 4 * r + 1 + 8 * t):
            guessm = guessm - 1
    else:
        pass
    print 'Case #%d: %d' % (i + 1, guessm)
