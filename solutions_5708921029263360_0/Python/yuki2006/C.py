def core():
    J, P, S, K = map(int, raw_input().split())
    check_jp = []
    check_js = []
    check_ps = []
    ans = []
    for j in xrange(1, J + 1):
        for p in xrange(1, P + 1):
            for s in xrange(1, S + 1):
                if K == check_jp.count((j, p)):
                    continue
                if K == check_js.count((j, s)):
                    continue
                if K == check_ps.count((p, s)):
                    continue
                check_jp.append((j, p))
                check_js.append((j, s))
                check_ps.append((p, s))
                ans.append((j, p, s))
    print len(ans)
    for a in ans:
        print " ".join(map(str, a))


T = int(raw_input())
for t in xrange(T):
    print "Case #" + str(t + 1) + ":",
    core()
