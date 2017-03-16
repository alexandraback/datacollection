def solve():
    k, c, s = map(int, raw_input().split())
    answer = []
    pt = 0
    while pt < k:
        cur = 0
        for i in xrange(c):
            if pt >= k:
                pt = k - 1
            cur = cur * k + pt
            pt += 1
        answer.append(str(cur + 1))
    if len(answer) > s:
        return "IMPOSSIBLE"
    else:
        return ' '.join(answer)

T = int(raw_input())
for case_no in xrange(1, T + 1):
    print "Case #%d: %s" % (case_no, str(solve()))

