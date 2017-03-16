#!/usr/bin/env python3
for t in range(int(input())):
    s = input()
    freq = {}
    words = \
        [ "ZERO"
        , "ONE"
        , "TWO"
        , "THREE"
        , "FOUR"
        , "FIVE"
        , "SIX"
        , "SEVEN"
        , "EIGHT"
        , "NINE"
        ]
    for c in ''.join(words):
        freq[c] = 0
    for c in s:
        freq[c] += 1
    cnt = [0] * 10
    def use(i, n):
        cnt[i] += n
        for c in words[i]:
            freq[c] -= n
    use(0, freq['Z'])
    use(2, freq['W'])
    use(6, freq['X'])
    use(8, freq['G'])
    use(7, freq['S'])
    use(5, freq['V'])
    use(4, freq['F'])
    use(1, freq['O'])
    use(3, freq['R'])
    use(9, freq['E'])
    ans = ''
    for c, n in zip('0123456789', cnt):
        ans += c * n
    print('Case #{}: {}'.format(t+1, ans))
