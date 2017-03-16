T = int(raw_input())

I,J,K = 2,3,4
mults = [[0 for j in xrange(5)] for i in xrange(5)]
for q in xrange(1,5):
    mults[q][q] = -1
    mults[1][q] = q
    mults[q][1] = q
mults[I][J] = K
mults[I][K] = -J
mults[J][I] = -K
mults[J][K] = I
mults[K][I] = J
mults[K][J] = -I

DEBUG = False

def m(a,b):
    if a * b > 0:
        sg = 1
    else:
        sg = -1
    return sg * mults[abs(a)][abs(b)]

def find_first_i(mlt, X=1, period=[1]):
    for i in xrange(len(period)):
        for j in xrange(len(mlt)):
            if m(period[i], mlt[j]) == I:
                return len(mlt) * i + j
    return len(mlt) * X + 1

def find_last_k(mlt, X=1, period=[1]):
    last_p = X % len(period)
    period = period[last_p:] + period[:last_p]
    period = period[::-1]
    for i in xrange(len(period)):
        for j in xrange(len(mlt)-1, -1, -1):
            if m(period[i], mlt[j]) == K:
                return len(mlt) * (X - i - 1) + j
    return -1

def get_mlt(s):
    mlt = [1 for i in xrange(len(s)+1)]
    for i in xrange(len(s)):
        mlt[i+1] = m(mlt[i], s[i])
    return mlt[1:]

def solve_hard(s, X):
    if X < 16:
        return solve_easy(s, X)
    mlt = get_mlt(s)
    if DEBUG:
        print mlt
    period = [1]
    while True:
        nxt = m(period[-1], mlt[-1])
        if nxt in period:
            break
        period.append(nxt)
    if DEBUG:
        print period
    last = period[X % len(period)]
    if last != -1:
        return False
    if DEBUG:
        print find_first_i(mlt, X, period), find_last_k(mlt, X, period)
    return find_first_i(mlt, X, period) < find_last_k(mlt, X, period)

def solve_easy(s, X):
    full = X * s
    mlt = get_mlt(full)
    if mlt[-1] != -1:
        return False
    if DEBUG:
        print find_first_i(mlt), find_last_k(mlt)
    return find_first_i(mlt) < find_last_k(mlt)


for case in xrange(1, T+1):
    L, X = map(int,raw_input().split())
    s = raw_input()
    s = [ord(c) - ord('i') + 2 for c in s]
    if DEBUG:
        print "easy"
        solve_easy(s, X)
    res = solve_hard(s, X)
    if res:
        res = "YES"
    else:
        res = "NO"
    print "Case #{}: {}".format(case, res)
