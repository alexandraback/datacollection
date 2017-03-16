for tc in range(1, int(raw_input())+1):
    r, c, w = map(int, raw_input().split())
    score = c/w*r
    if c%w:
        score += w
    else:
        score += w-1
    print "Case #%d: %d" % (tc, score)