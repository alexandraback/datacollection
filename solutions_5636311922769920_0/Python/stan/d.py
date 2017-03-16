import sys

def solve(k, c, s):
    if c * s < k:
        return "IMPOSSIBLE"
    res = []
    pos = 0
    while pos < k:
        subtree_size = k ** c / k
        global_pos = pos * subtree_size
        pos += 1
        while subtree_size > 1 and pos < k:
            subtree_size /= k
            global_pos += pos * subtree_size
            pos += 1
        res.append(global_pos)
    return " ".join(map(lambda x: str(x + 1), res))

nt = int(sys.stdin.readline())
for tc in xrange(1, nt + 1):
    k, c, s = map(int, sys.stdin.readline().split())
    print "Case #%d: %s" % (tc, solve(k, c, s))
