

def calc_quaternion(sign, a, b):
    if a == '':
        return (sign, b)
    elif b == '':
        return (sign, a)
    elif a == 'i':
        if b == 'i':
            return (-sign, '')
        elif b == 'j':
            return (sign, 'k')
        elif b == 'k':
            return (-sign, 'j')
    elif a == 'j':
        if b == 'i':
            return (-sign, 'k')
        elif b == 'j':
            return (-sign, '')
        elif b == 'k':
            return (sign, 'i')
    elif a == 'k':
        if b == 'i':
            return (sign, 'j')
        elif b == 'j':
            return (-sign, 'i')
        elif b == 'k':
            return (-sign, '')
    assert False

T = int(raw_input())
for t in xrange(T):
    L, X = map(int, raw_input().split())
    S = raw_input()

    # calculate all
    total_sign, total_value = 1, ''
    for i in xrange(L * X):
        total_sign, total_value = calc_quaternion(total_sign, total_value, S[i % L])

    # calculate lengths of left-side substring which reduces to i
    left_list = []
    left = 1
    sign = 1
    value = ''
    while left < L * X:
        sign, value = calc_quaternion(sign, value, S[(left - 1) % L])
        if (sign, value) == (1, 'i'):
            left_list.append(left)
        left += 1

    # calculate lengths of right-side substring which reduces to k
    right_list = []
    right = 1
    sign = 1
    value = ''
    while right < L * X:
        sign, value = calc_quaternion(sign, value, S[-right % L])
        if right == 1:
            if (sign, value) == (1, 'k'):
                right_list.append(right)
        elif (sign, value) == (-1, 'k'):
            right_list.append(right)
        right += 1

    found = False
    for left in left_list:
        for right in right_list:
            if L * X < left + right + 1:
                break

            # calculate middle substring value
            for xsign, xvalue in (
                    (1, ''), (1, 'i'), (1, 'j'), (1, 'k'),
                    (-1, ''), (-1, 'i'), (-1, 'j'), (-1, 'k')):
                a, b = 1, 'i'
                c, d = calc_quaternion(a * xsign, b, xvalue)
                e, f = calc_quaternion(c, d, 'k')
                if (e, f) == (total_sign, total_value):
                    break
            if (xsign, xvalue) == (1, 'j'):
                found = True
                break
        if found:
            break

    print 'Case #{}: {}'.format(t + 1, 'YES' if found else 'NO')
