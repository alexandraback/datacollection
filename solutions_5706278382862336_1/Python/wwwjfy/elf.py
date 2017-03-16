import math


def gcd(a, b):
    while b:
        a, b = b, a % b
    return a


for i in range(int(raw_input())):
    P, Q = raw_input().split('/')
    P, Q = int(P), int(Q)
    d = gcd(P, Q)
    P, Q = P / d, Q / d
    q_to_2 = int(math.log(Q, 2))
    if 2 ** q_to_2 != Q:
        print('Case #%s: impossible' % (i + 1, ))
    else:
        p_to_2 = int(math.log(P, 2))
        result = q_to_2 - p_to_2
        if result > 40:
            print('Case #%s: impossible' % (i + 1, ))
        else:
            print('Case #%s: %s' % (i + 1, result))

