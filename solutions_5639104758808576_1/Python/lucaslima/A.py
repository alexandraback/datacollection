T = int(raw_input())
for case in xrange(T):
    [_, audience] = raw_input().split(" ")
    audience = map(int,list(audience))
    total, answer = 0, 0
    for (s,cnt) in enumerate(audience):
        if total < s:
            answer += s - total
            total = s
        total += cnt
    print "Case #%d: %d" % (case + 1, answer)
