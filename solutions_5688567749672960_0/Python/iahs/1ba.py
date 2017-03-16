from sys import stdin
from collections import deque
T = int(stdin.readline())
for case in xrange(1, T+1):
    n = int(stdin.readline())
    q = deque([1])
    seen = {1: 1}
    while n not in seen:
        num = q.popleft()
        inc = num + 1
        rev = int(str(num)[::-1])
        if inc not in seen:
            seen[inc] = seen[num] + 1
            q.append(inc)
        if rev > inc and rev not in seen:
            seen[rev] = seen[num] + 1
            q.append(rev)
    print "Case #%d: %d" % (case, seen[n])
