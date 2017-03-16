from multiprocessing import Pool

d = ["ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"]
for i in xrange(len(d)):
    count = [0] * 30
    for ch in d[i]:
        count[ord(ch) - ord('A')] += 1
    count[29] = len(d[i])
    d[i] = count

memo = {}
def dfs(count):
    if count in memo:
        return memo[count]
    if count[29] < 0:
        return '!'
    if count[29] == 0:
        return ''
    for i in xrange(len(d)):
        c = d[i]
        ok = True
        for j in xrange(29):
            if count[j] < c[j]:
                ok = False
                break
        if ok and count[29] >= c[29]:
            cc = list(count[:])
            for j in xrange(30):
                cc[j] -= c[j]
            s = dfs(tuple(cc))
            if s != '!':
                memo[count] = str(i) + s
                return memo[count]
    memo[count] = '!'
    return memo[count]

def solve():
    S = raw_input()
    count = [0] * 30
    for ch in S:
        count[ord(ch) - ord('A')] += 1
    count[29] = len(S)
    m = ''
    c0 = count[25]
    for i in xrange(30):
        count[i] -= d[0][i] * c0
    m += '0' * c0
    c2 = count[22]
    for i in xrange(30):
        count[i] -= d[2][i] * c2
    m += '2' * c2
    c4 = count[20]
    for i in xrange(30):
        count[i] -= d[4][i] * c4
    m += '4' * c4
    c6 = count[23]
    for i in xrange(30):
        count[i] -= d[6][i] * c6
    m += '6' * c6
    c8 = count[6]
    for i in xrange(30):
        count[i] -= d[8][i] * c8
    m += '8' * c8
    m += dfs(tuple(count))
    l = list(m)
    l.sort()
    return ''.join(l)

T = int(raw_input())
for i in range(T):
    print 'Case #%d:' % (i + 1), solve()

# T = int(raw_input())
# p = Pool(4)
# args = []
# for i in range(T):
#     S = raw_input()
#     args.append(S)
# ans = p.map(solve, args)
# for i in range(T):
#     print 'Case #%d:' % (i + 1), ans[i]
