import sys
from collections import defaultdict

l = ["ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"]

T = int(sys.stdin.readline())
case = 1
for case in range(1, T+1):
    s = sys.stdin.readline().strip()
    d = defaultdict(int)
    for c in s:
        d[c] += 1
    digits = []
    for cand in [("Z", 0), ("W", 2), ("X", 6), ("G", 8), ("U", 4),
                 ("O", 1), ("R", 3), ("F", 5), ("V", 7), ("N", 9)]:
                     while d[cand[0]] > 0:
                         digits.append(cand[1])
                         for c in l[cand[1]]:
                             d[c] -= 1
    print "Case #{0}:".format(case), "".join(map(str, sorted(digits)))
    #case += 1
        
