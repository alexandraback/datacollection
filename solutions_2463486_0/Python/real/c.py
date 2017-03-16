read_ints = lambda: map(int, raw_input().split())

# pal: palindrome
def is_pal(x):
    x = str(x)
    for _ in xrange(len(x)/2):
        if x[_] != x[-_-1]:
            return False
    else:
        return True

def gen1(x):
    x = str(x)
    return x + ''.join(reversed(x))

def gen2(x):
    x = str(x)
    return x + ''.join(reversed(x[:-1]))

def gen_all(BOUND=10**14 + 2036):
    sqs = []
    pals = []
    for x in xrange(1, 10369):
        pals.append(gen1(x))
        pals.append(gen2(x))

    pals = sorted(map(int, pals))
    for _ in pals:
        sq = int(_) * int(_)
        if sq > BOUND:
            break
        if is_pal(sq):
            sqs.append(sq)
    return sqs

sqs = gen_all()
T = int(raw_input())
for no_t in xrange(1, T + 1):
    A, B = read_ints()
    ans = 0
    for _ in sqs:
        if A <= _ <= B:
            ans += 1
    print 'Case #%d: %s' % (no_t, ans)
