from sys import stderr
t = int(input())
def search(start, origin, cnt, visited):
    cur = last = start
    while cur not in visited:
        visited.add(cur)
        if bff[cur] == last:
            best = len(visited)
            # We've looped back on ourselves! We can try to find another set (which is either self sufficient in itself, or links to our head or tail)
            for i in range(n):
                if i not in visited:
                    best = max(best, search(i, origin, cur, set(visited)))
            return best
        last = cur
        cur = bff[cur]
    return len(visited) if cur in (origin, cnt) else 0

for cn in range(t):
    n = int(input())
    bff = list(map(lambda v: int(v) - 1, input().split()))
    best = 0
    for i in range(n):
        best = max(best, search(i, i, None, set()))
    print("Case #%d: %d" % (cn + 1, best))
