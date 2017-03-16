def read(t):
    return t(raw_input().strip())


def read_arr(t):
    return map(t, raw_input().strip().split())


def rev_neg_num(n):
    return int("-" + (str(n)[1:])[::-1])

memz = {}
for i in xrange(1, 10**6 + 1):
    if i <= 20:
        memz[i] = i
    elif i % 10 == 0:
        memz[i] = memz[i-1] + 1
    else:
        rev = int(str(i)[::-1])
        if rev in memz:
            memz[i] = min(memz[i-1] + 1, memz[rev] + 1)
        else:
            memz[i] = memz[i-1] + 1


def solve(N):
    return memz[N]

solve(10**6)

for T in xrange(input()):
    print "Case #%d:" % (T+1, ),
    print solve(read(int))
