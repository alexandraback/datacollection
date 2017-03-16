from collections import Counter

T = input()

for case_num in xrange(T):
    S = raw_input()

    ans = S[0]
    for c in S[1:]:
        if c >= ans[0]:
            ans = c + ans
        else:
            ans = ans + c

    print 'Case #%d: %s' % (case_num + 1, ans)
