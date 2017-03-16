if __name__ == '__main__':
    for caseno in xrange(int(raw_input())):
        inp = [int(s) for s in raw_input().split()]
        N, S, p = inp[0:3]
        ts = inp[3:]

        cnt = 0
        for t in sorted(ts, reverse=True):
            if t == 0:
                if p == 0:
                    cnt += 1
            elif t >= p * 3 - 2:
                cnt += 1
            elif t >= p * 3 - 4:
                if S > 0:
                    cnt += 1
                    S -= 1

                if S == 0:
                    break

        print 'Case #%d: %d' % (caseno + 1, cnt)
