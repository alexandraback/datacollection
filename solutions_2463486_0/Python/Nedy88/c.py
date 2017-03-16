import sys

global dp

MAXLEN = 25
MAXSUM = 9

def palin(num):
    s = str(num)
    for i in range(len(s)):
        if s[i] != s[len(s) - 1 - i]:
            return False
    return True

def f(pos, s):
    global dp
    if dp[pos][s] != -1:
        return dp[pos][s]
    if pos == 25:
        dp[pos][s] = 1
        return 1

    ret = 1
    for dig in range(0, 10):
        if pos == 0 and dig == 0:
            continue
        if dig * dig + s >= 10:
            continue
        ret += f(pos + 1, s + dig * dig)

    dp[pos][s] = ret
    return ret

def getCandidates(pos, s, prefix):
    ret = []
    if pos > 0:
        if s + s <= MAXSUM:
            temp = int(prefix + prefix[::-1])
            temp = temp * temp
            if palin(temp):
                ret.append(temp)
        last = int(prefix[len(prefix) - 1])
        if s + s - last * last <= MAXSUM:
            temp = int(prefix + prefix[::-1][1:])
            temp = temp * temp
            if palin(temp):
                ret.append(temp)

    if pos == MAXLEN:
        return ret

    for dig in range(0, 4):
        if pos == 0 and dig == 0:
            continue
        if dig * dig + s > MAXSUM:
            continue
        ret.extend(getCandidates(pos + 1, dig * dig + s, prefix + str(dig)))

    return ret

def sumSquares(s):
    ret = 0
    for ch in s:
        x = int(ch)
        ret = ret + x * x

    x = int(s[len(s) - 1])
    return (ret, x * x)

def binSearch(vec, x):
    L = 0
    R = len(vec)
    while R - L > 1:
        Q = (L + R) / 2
        if vec[Q] == x:
            return Q + 1
        if vec[Q] > x:
            R = Q
        else:
            L = Q
    return L + 1

if __name__ == '__main__':
    global dp
    dp = [[-1 for _ in range(10)] for x in range(26)]
    cands = getCandidates(0, 0, '')
    cands.sort()
    T = int(sys.stdin.readline())
    for test in range(1, T + 1):
        A, B = [int(_) for _ in sys.stdin.readline().split()]
        big = binSearch(cands, B)
        small = 0
        if A > 1:
            small = binSearch(cands, A - 1)
        print 'Case #{0}: {1}'.format(test, big - small)
