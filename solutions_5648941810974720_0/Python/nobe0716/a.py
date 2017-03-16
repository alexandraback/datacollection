__author__ = 'sunghyo.jung'

from collections import Counter
nums = ["ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"]
#           Z                                            X                 G
#                               H
#                                       R
#                                                               S
#                       T
#                                               V
#                O
#                                                                                  E
def reduce(c, idx):
    for elem in nums[idx]:
        c[elem] -= 1
    return c


def match_chr(c, r, chr, idx):
    for i in range(c[chr]):
        c = reduce(c, idx)
        r.append(idx)
    return c, r
for t in range(1, int(input().strip()) + 1):
    s = input().strip()
    c = Counter(s)
    r = []
    c, r = match_chr(c, r, "Z", 0)
    c, r = match_chr(c, r, "X", 6)
    c, r = match_chr(c, r, "G", 8)
    c, r = match_chr(c, r, "H", 3)
    c, r = match_chr(c, r, "R", 4)
    c, r = match_chr(c, r, "S", 7)
    c, r = match_chr(c, r, "T", 2)
    c, r = match_chr(c, r, "V", 5)
    c, r = match_chr(c, r, "O", 1)
    c, r = match_chr(c, r, "O", 1)
    c, r = match_chr(c, r, "E", 9)

    ans = "".join(sorted(map(str,r)))
    print("Case #%d: %s" % (t, ans))