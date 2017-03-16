# Let i be the number of characters typed so far
# and n be the number of characters in the pw
# and k be the position of the first error

# C(i, n) is the # keystrokes till the password is complete
# Three options:
# 1. finish typing, press enter
#    C_1(i, k, n) = (n - i) + 1
#                 = n - i + 1
# 2. backspace to the first error, retype from then, press enter
#    C_2(i, k, n) = (i - k + 1) + (n - k) + 1
#                 = n - 2k + i + 2
# 3. press enter, retype, press enter
#    C_3(i, k, n) = 1 + n + 1
#                 = n + 2

# We can discount the possibility of backspacing to !first error, since the
# other options make that always more expensive.

from operator import mul
product = lambda x: reduce(mul, x)

def expected_keep_typing(p_no_errors, i, n):
#    p_no_errors = product(P)
    p_any_error = 1 - p_no_errors

    # if we keep typing, then:
    c1_no_errors = n - i + 1
    c1_any_error = c1_no_errors + n + 1

#    print p_no_errors, p_any_error
#    print c1_no_errors, c1_any_error

    return (
        c1_no_errors * p_no_errors +
        c1_any_error * p_any_error
    )

n_cases = int(raw_input())
for case in xrange(1, n_cases + 1):
    i, n = map(int, raw_input().split())
    P = map(float, raw_input().split())
    assert len(P) == i

    Pk = []
    pp = 1.0
    for p in P:
        pp *= p
        Pk.append(pp)

#    if case < 3:
#        continue

#    print i, n, P

    ec1 = expected_keep_typing(Pk[-1], i, n)

    # let k be the number of times I press backspace
    # we ignore backspacing all the characters
    ec2s = []
    for k in xrange(1, i):
#        print P[:-k]
        ec2 = expected_keep_typing(Pk[-k-1], i - k, n) + k
        ec2s.append(ec2)
#        print 'k =', k, 'ec2 =', ec2

    ec2 = float('infinity')
    if ec2s:
        ec2 = min(ec2s)

    c3 = n + 2

#    print ec1, ec2, c3

    e = min(ec1, ec2, c3)
    print 'Case #%d: %.6f' % (case, e)

