sol = None
sols = {}

def solve(S, i, k, s, c):
    global sol, sols

    if sol:
        return

    if s and c:
        if s in sols:
            sol = sols[s], k

        sols[s] = k

    if i >= len(S):
        return

    solve(S, i + 1, k | (2**i), s + S[i], 1)
    solve(S, i + 1, k, s, 0)

if __name__ == '__main__':
    for caseno in xrange(int(raw_input())):
        S = [int(s) for s in raw_input().split()]
        N = S[0]
        S = list(set(S[1:]))
        N = len(S)

        sol = None
        sols = {}
        solve(S, 0, 0, 0, 0)

        print 'Case #%d:' % (caseno + 1)
        if not sol:
            print 'Impossible'
        else:
            nums = []
            for i in xrange(0, N):
                if sol[0] & (2**i):
                    nums += [str(S[i])]
            print ' '.join(nums)

            nums = []
            for i in xrange(0, N):
                if sol[1] & (2**i):
                    nums += [str(S[i])]

            print ' '.join(nums)
