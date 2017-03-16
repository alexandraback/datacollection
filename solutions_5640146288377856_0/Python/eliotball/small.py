def solve(c, w):
    initial = c / w
    #print "initial", initial
    gap = c - (initial * w)
    #print "gap", gap
    forced = (initial * w) - (c - w) - 1
    #print "forced", forced
    rem = w - forced - 1
    block = 1
    if (c - (1 + gap + forced)) % w == 0:
        block = 0
    return initial + forced + rem + block


if __name__ == "__main__":
    case_count = int(raw_input())
    for case_num in xrange(1, case_count + 1):
        r, c, w = [int(i) for i in raw_input().split()]
        print "Case #%s: %s" % (case_num, solve(c, w))
