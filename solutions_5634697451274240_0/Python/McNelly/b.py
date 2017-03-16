from collections import deque

def upper_bound(s):
    pre = -1
    l = []
    for i, item in enumerate(s):
        if item == '+':
            pre = 1
        elif pre != 0:
            l.append(i)
            pre = 0
    res = len(l) * 2
    if l and l[0] == 0:
        res -= 1
    return res

def do_reverse(s):
    s = s[::-1]
    return ''.join(
            map(lambda x: {'+': '-', '-': '+'}[x], s))

def bfs(s):
    q = deque()
    q.append(s)
    d = {s: 0}
    ub = upper_bound(s)
    while q:
        cur = q.popleft()
        step = d[cur]
        if upper_bound(cur) == 0:
            return step

        if step > ub:
            continue

        for i in xrange(1, len(cur) + 1):
            next = do_reverse(cur[:i]) + cur[i:]
            next_step = step + 1

            if next not in d or next_step < d[next]:
                d[next] = next_step
                q.append(next)
    return None

T = int(raw_input())
for case_ in xrange(T):
    s = raw_input()
    print "Case #%d:" % (case_ + 1), bfs(s)

