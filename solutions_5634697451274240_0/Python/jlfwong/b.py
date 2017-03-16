T = input()

def solve(S, target='+'):
    if len(S) == 0:
        return 0

    if S[-1] == target:
        # Last pancake is already target orientation
        return solve(S[:-1], target)
    else:
        # Last pancake needs flipping
        return 1 + solve(S[:-1],
                         '-' if target == '+' else '+')

for case_num in xrange(T):
    S = raw_input()
    ans = solve(S)
    print 'Case #%d: %s' % (case_num + 1, ans)
