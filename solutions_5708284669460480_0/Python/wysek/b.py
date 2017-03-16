def generateString(K, S, res = None, depth = 0):
    if res is None:
        res = [None] * S
    if depth == S:
        yield res
    else:
        for k in K:
            res[depth] = k
            for r in generateString(K, S, res, depth+1):
                yield r

def bananas(s, L):
    s = ''.join(s)
    res = -1
    i = 0
    while i != -1:
        res += 1
        i = s.find(L, i)
        if i >= 0: i += 1
    return res

def solve():
    K, L, S = [int(x) for x in raw_input().split()]
    K = raw_input()
    L = raw_input()
    B = []
    for s in generateString(K, S):
        b = bananas(s, L)
        B.append(b)
    m = max(B)
    res = float(sum([m-b for b in B])) / len(B)
    return res

def main():
    T = int(raw_input())
    for t in xrange(1, T+1):
        print "Case #%d: %.6f" % (t, solve())

if __name__ == '__main__':
    main()

