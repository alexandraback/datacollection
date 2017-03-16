I, J, K = 'i', 'j', 'k'


class Q(object):
    def __init__(self, sign, value):
        assert sign in (1, -1)
        assert value in (1, I, J, K)
        self.sign = sign
        self.value = value

    def __mul__(a, b):
        if a.value == 1:
            return Q(a.sign * b.sign, b.value)
        elif b.value == 1:
            return Q(a.sign * b.sign, a.value)

        ret = Q(a.sign * b.sign, 1)
        if (a.value, b.value) not in ((I, J), (J, K), (K, I)):
            ret.sign *= -1
        if a.value == b.value:
            ret.value = 1
        else:
            s = {I, J, K}
            s.remove(a.value)
            s.remove(b.value)
            ret.value = s.pop()
        return ret

    def __eq__(a, b):
        return a.sign == b.sign and a.value == b.value

    def __pow__(a, b):
        assert isinstance(b, (int, long))
        assert 0 <= b
        ret = Q(1, 1)
        m = a
        while 0 < b:
            if b & 1:
                ret = ret * m
            m = m * m
            b >>= 1
        return ret

    def __neg__(self):
        return Q(-self.sign, self.value)

T = int(raw_input())
for t in xrange(T):
    L, X = map(int, raw_input().split())
    S = raw_input()

    # calculate all
    total = Q(1, 1)
    for i in xrange(L):
        total = total * Q(1, S[i])
    total = total ** (X % 4)

    # calculate lengths of left-side substring which reduces to i
    lefts = []
    left = 1
    x = Q(1, 1)
    while left < min(X, 4) * L:
        x = x * Q(1, S[(left - 1) % L])
        if x == Q(1, I):
            lefts.append(left)
            break
        left += 1

    # calculate lengths of right-side substring which reduces to k
    rights = []
    if S[-1] == 'k':
        rights.append(1)
    else:
        x = Q(1, S[L - 1])
        right = 2
        while right < min(X, 4) * L:
            x = x * Q(1, S[-right % L])
            if x == Q(-1, K):
                rights.append(right)
                break
            right += 1

    found = lefts and rights and lefts[0] + rights[0] < L * X and total == Q(-1, 1)
    print 'Case #{}: {}'.format(t + 1, 'YES' if found else 'NO')
