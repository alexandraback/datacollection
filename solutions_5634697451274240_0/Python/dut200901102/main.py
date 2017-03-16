for _ in xrange(input()):
    print "Case #%d:" % (_ + 1),
    s = raw_input()
    seg_cnt = 1
    for i in xrange(1, len(s)):
        if s[i] != s[i - 1]:
            seg_cnt += 1
    if s[-1] == '+':
        seg_cnt -= 1
    print seg_cnt