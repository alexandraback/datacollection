def best(x):
    a = b = c = x / 3

    if a + b + c < x:
        c += 1

    if a + b + c < x:
        b += 1

    if b == c and c > 0:
        # Surprising score only increases best score
        # if unsurprising triplet has two equal maximums
        return (c, c + 1)
    else:
        return (c, c)

casenum = 1
def doit(case):
    global casenum
    case = [int(x) for x in case.split(' ')]

    N, S, p = case[:3]
    t = case[3:]

    bests = [(best(x)) for x in t]

    ans = 0

    for normal, surprise in bests:
        if normal >= p:
            ans += 1
        elif surprise >= p and S > 0:
            ans += 1
            S -= 1

    print 'Case #%d: %d' % (casenum, ans)
    casenum += 1

raw = [x.strip() for x in open('B-large.in').readlines()]
ZZZ = int(raw[0])
data = raw[1:]
for case in range(ZZZ):
    doit(data[case])
