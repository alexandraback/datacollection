digits = ["ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"]
# Z - ZERO
# W - TWO
# U - FOUR
# R - THREE
# O - ONE
# X - SIX
# S - SEVEN
# G - EIGHT
# F - FIVE
# I - NINE

from collections import Counter

def dec(d, w, c):
    for ch in w:
        d[ch] -= c

n = int(input())
for t in range(1, n + 1):
    s = input().strip()
    d = Counter()
    for w in digits:
        for ch in w:
            d[ch] = 0
    for ch in s:
        d[ch] += 1
    cnt = [0] * 10
    cnt[0] = d['Z']
    dec(d, "ZERO", cnt[0])
    cnt[2] = d['W']
    dec(d, "TWO", cnt[2])
    cnt[4] = d['U']
    dec(d, "FOUR", cnt[4])
    cnt[3] = d['R']
    dec(d, "THREE", cnt[3])
    cnt[1] = d['O']
    dec(d, "ONE", cnt[1])
    cnt[6] = d['X']
    dec(d, "SIX", cnt[6])
    cnt[7] = d['S']
    dec(d, "SEVEN", cnt[7])
    cnt[8] = d['G']
    dec(d, "EIGHT", cnt[8])
    cnt[5] = d['F']
    dec(d, "FIVE", cnt[5])
    cnt[9] = d['I']
    dec(d, "NINE", cnt[9])
    assert all(v == 0 for v in d.values())
    ans = ''.join(str(i) * cnt[i] for i in range(10))
    print("Case #{}: {}".format(t, ans))

    
