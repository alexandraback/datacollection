T = int(raw_input())

I,J,K = 2,3,4
mults = [[0 for j in xrange(5)] for i in xrange(5)]
for q in xrange(1,5):
    mults[1][q] = q
    mults[q][1] = q
    mults[q][q] = -1
mults[I][J] = K
mults[I][K] = -J
mults[J][I] = -K
mults[J][K] = I
mults[K][I] = J
mults[K][J] = -I

def find_first_i(mlt, X):
    for i in xrange(len(mlt)):
        if mlt[i] == I:
            return i
    return len(mlt) * X

def find_last_k(mlt, X):
    for i in xrange(len(mlt)-1, -1, -1):
        if mlt[i] == K:
            return i
    return 0


def solve_easy(s, X):
    full = []
    for i in xrange(X):
        full += s
    mlt = [1 for i in xrange(len(full)+1)]
    for i in xrange(len(full)):
        if mlt[i] > 0:
            sg = 1
        else:
            sg = -1
        mlt[i+1] = sg * mults[abs(mlt[i])][full[i]]
    if mlt[len(full)] != -1:
        return False
    return find_first_i(mlt, 1) < find_last_k(mlt, 1)


for case in xrange(1, T+1):
    L, X = map(int,raw_input().split())
    s = raw_input()
    s = [ord(c) - ord('i') + 2 for c in s]
    res = solve_easy(s, X)
    if res:
        res = "YES"
    else:
        res = "NO"
    print "Case #{}: {}".format(case, res)
