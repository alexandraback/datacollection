if __name__ == '__main__':
    T = int(raw_input())
    for t in xrange(1, T + 1):
        R, C, W = map(int, raw_input().split())
        cnt = 0
        if C % W == 0:
            cnt += (C / W - 1) * R + (R - 1) + W
        else:
            cnt += (C / W) * R + W
        print "Case #%d: %d" % (t, cnt)