if __name__ == '__main__':
    for caseno in xrange(int(raw_input())):
        A, B = [int(s) for s in raw_input().split()]

        cnt = 0
        for i in xrange(A, B):
            s = str(i)
            seen = {}
            for j in xrange(1, len(s)):
                t = int(s[j:] + s[:j])
                if t not in seen and i < t <= B:
                    seen[t] = True
                    cnt += 1

        print 'Case #%d: %d' % (caseno + 1, cnt)
