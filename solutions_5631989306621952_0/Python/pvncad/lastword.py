import sys

N = int(sys.stdin.readline())

for tc in xrange(1, N + 1):
    word = sys.stdin.readline().strip()
    ans = []
    for c in word:
        if len(ans) == 0:
            ans.append(c)
            max_char = c
            continue

        if c >= max_char:
            ans.insert(0, c)
            max_char = c
        else:
            ans.append(c)
    print "Case #%d: %s" % (tc, "".join(ans))
