import sys
sys.stdin = open('test.txt', 'r')
sys.stdout = open('ans.txt', 'w')


table = {
    '1': {'1': '1', 'i': 'i', 'j': 'j', 'k': 'k'},
    'i': {'1': 'i', 'i': '-1', 'j': 'k', 'k': '-j'},
    'j': {'1': 'j', 'i': '-k', 'j': '-1', 'k': 'i'},
    'k': {'1': 'k', 'i': 'j', 'j': '-i', 'k': '-1'},
}


def power(var, times):
    res = '1'
    while times:
        if times & 1:
            res = mult(res, var)
        var = mult(var, var)
        times >>= 1
    return res


def mult(x, y):
    flagx = -1 if '-' in x else 1
    flagy = -1 if '-' in y else 1
    x = x.strip('-')
    y = y.strip('-')
    res = table[x][y]
    if flagx * flagy == -1:
        if '-' in res:
            res = res.strip('-')
        else:
            res = '-' + res
    return res


def gen_header(l, x, s, single):
    for i in range(min(5, x)):
        f = power(single, i)
        # print '%s power %d is %s' % (single, i, f)
        for j in range(len(s)):
            # print 'mult(%s, %s) is %s' % (f, s[j], mult(f, s[j]))
            f = mult(f, s[j])
            if f == 'i':
                return i * l + j + 1
    return -1


def gen_tail(l, x, s, single):
    for i in range(min(5, x)):
        f = power(single, i)
        for j in range(len(s)):
            f = mult(s[len(s) - 1 - j], f)
            if f == 'k':
                return i * l + j + 1
    return -1


def solve(l, x, s):
    single = '1'
    for each in s:
        single = mult(single, each)
    # print 'single: ', single

    final = power(single, x)
    # print 'final: ', final
    if final != '-1':
        return 'NO'

    cnti = gen_header(l, x, s, single)
    # print 'cnti: ', cnti
    if cnti == -1:
        return 'NO'

    cntk = gen_tail(l, x, s, single)
    # print 'cntk: ', cntk
    if cntk == -1:
        return 'NO'

    if cnti + cntk >= x * l:
        return 'NO'

    return 'YES'


T = input()
for t in range(T):
    l, x = map(int, raw_input().split())
    s = raw_input()
    ans = solve(l, x, s)
    print 'Case #%d: %s' % (t+1, ans)
