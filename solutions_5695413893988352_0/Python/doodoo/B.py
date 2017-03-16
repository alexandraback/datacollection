import itertools

def replace(C, J, comb):
    c = list(C)
    j = list(J)

    cur = 0

    for i in xrange(len(c)):
        if c[i] == '?':
            c[i] = comb[cur]
            cur += 1

    for i in xrange(len(j)):
        if j[i] == '?':
            j[i] = comb[cur]
            cur += 1

    return ''.join(c), ''.join(j)

def solve(C, J):
    c_count = C.count('?')
    j_count = J.count('?')

    c_res = None
    j_res = None
    val_res = None

    for comb in itertools.product('0123456789', repeat=(c_count + j_count)):
        c, j = replace(C, J, comb)
#        print c, j

        if val_res is None:
            c_res = c
            j_res = j
            val_res = abs(int(c) - int(j))
            continue

        val = abs(int(c) - int(j))
        if val > val_res:
            continue

        if val < val_res:
            c_res = c
            j_res = j
            val_res = val
            continue

        if int(c) < int(c_res):
            c_res = c
            j_res = j
            val_res = val
            continue

        if int(j) < int(j_res):
            c_res = c
            j_res = j
            val_res = val
            continue

    return c_res, j_res

T = int(raw_input())

for i in xrange(T):
    C, J = raw_input().split()
    c, j = solve(C, J)

    print 'Case #%d: %s %s' % (i + 1, c, j)
