import sys
import collections

def solve(testcase):
    n = int(sys.stdin.readline().strip())
    cnt = collections.defaultdict(int)
    for i in range(2*n-1):
        x = map(int, sys.stdin.readline().strip().split())
        for y in x:
            cnt[y] += 1

    res = [y for y in sorted(cnt.keys()) if cnt[y] % 2 == 1]
    print "Case #%d: %s" % (testcase, " ".join(str(x) for x in res))

for t in range(int(sys.stdin.readline().strip())):
    solve(t+1)
