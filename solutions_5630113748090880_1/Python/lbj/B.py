from collections import Counter
from sys import stderr
t = int(input())
for cn in range(t):
    n = int(input())
    al = []
    for c in range(n * 2 - 1):
        vs = list(map(int, input().split()))
        al.extend(vs)
    c = Counter(al)
    od = [v for v,k in c.items() if k & 1]
    if len(od) != n:
        print("Size mismatch!", file=stderr)
    print("Case #%d: %s" % (cn + 1, " ".join(map(str, sorted(od)))))
