fn = raw_input()
rfp = open(fn + '.in', 'r')
wfp = open(fn + '.out', 'w')
T = int(rfp.readline())
def get_num(s):
    a = []
    for i in range(31, -1, -1):
        if s & (1 << i):
            a.append(i)
    return a

def get_count_of_zero(x, b):
    t = x - (((1 << (b + 1)) - 1) & x)
    t >>= 1
    if (1 << b) & x:
        s = 1 << b
    else:
        s = ((1 << b) - 1) & x
    return t + s


def read_array():
    return map(lambda(x): int(x), rfp.readline().split(' '))

for k in range(T):
    A, B, K = read_array()
    a = get_num(A)
    b = get_num(B)
    t = get_num(K)
    ans = 0
    for i in t:
        t1 = get_count_of_zero(A, i)
        t2 = get_count_of_zero(B, i)
        ans += t1 * t2 + (A - t1) * t2 + t1 * (B - t2)
        A -= t1
        B -= t2
        if A == 0 or B == 0:
            break
    result_string = 'Case #{0}: {1}\n'.format(k + 1, ans)
    wfp.write(result_string)
    print result_string