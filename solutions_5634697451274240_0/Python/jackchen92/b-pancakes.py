def main():
    T = int(raw_input())
    for t in xrange(1, T+1):
        s = raw_input()
        s = [ch == '+' for ch in s]
        f = True
        a = 0
        for p in reversed(s):
            if f != p:
                a += 1
                f = not f
        print 'Case #%d: %d' % (t, a)

main()
