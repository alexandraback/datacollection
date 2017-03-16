import sys
import collections

DIGITS_STR = [
    "ZERO",
    "TWO",
    "FOUR",
    "SIX",
    "EIGHT",
    "FIVE",
    "NINE",
    "THREE",
    "SEVEN",
    "ONE",
]

DIGITS = [0, 2, 4, 6, 8, 5, 9, 3, 7, 1]

def fits(d, cnt):
    c = collections.defaultdict(int)
    for i in d:
        c[i] += 1
        if c[i] > cnt[i]:
            return False
    return True

nt = int(sys.stdin.readline())
for t in xrange(1, nt + 1):
    s = sys.stdin.readline().strip()
    cnt = collections.defaultdict(int)
    for c in s:
        cnt[c] += 1
    ans = []
    for d_str, d in zip(DIGITS_STR, DIGITS):
        while fits(d_str, cnt):
            print >> sys.stderr, d_str, d, 'fits', cnt
            for c in d_str:
                cnt[c] -= 1
            ans.append(d)
    assert all(i == 0 for _, i in cnt.items())
    ans.sort()
    print "Case #%d:" % t, "".join(map(str, ans))
