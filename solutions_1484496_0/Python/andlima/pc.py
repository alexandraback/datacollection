def solve(N, S):
    d = {}
    for mask in xrange(1, 1 << N):
        s = sum(S[i] for i in range(N) if mask & (1 << i))
        if d.get(s, False):
            mask2 = d[s]
            return [' '.join(str(S[i]) for i in range(N) if mask2 & (1 << i)),
                    ' '.join(str(S[i]) for i in range(N) if mask & (1 << i))]
        d[s] = mask
    return False

if __name__ == '__main__':
    T = int(raw_input())
    for t in range(T):
        items = [int(item) for item in raw_input().split(' ')]
        N = items[0]
        S = items[1:]
        answer = solve(N, S)
        print 'Case #%d:' % (t + 1)
        if answer:
            print answer[0]
            print answer[1]
        else:
            print "Impossible"
