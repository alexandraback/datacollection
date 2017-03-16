from collections import Counter

mp = [
    (0, "ZERO"), (6, "SIX"), (2, "TWO"), (4, "FOUR"), (3, "THREE"),
    (8, "EIGHT"), (7, "SEVEN"), (5, "FIVE"), (1, "ONE"), (9, "NINE")
]

t = int(raw_input())

for tt in (xrange(1, t + 1)):
    s = raw_input()
    c = Counter(s)
    ans = []
    for k, v in mp:
        ct = min([c[lt] for lt in v])
        c.subtract(v * ct)
        ans += [k] * ct
    print "Case #{}: {}".format(tt, ''.join(map(str, sorted(ans))))
