#f = open('B.in')
#def input():
#    return next(f)

for x in range(1, int(input()) + 1):
    K, L, S = map(int, input().split())
    keys, target = input().strip(), input().strip()
    def doit():
        if S < len(target) or not set(target) <= set(keys):
            return 0
        expected = S - L + 1
        for t in target:
            expected *= keys.count(t) / len(keys)
        for i in range(len(target)+1):
            if (target[:i] * 10).startswith(target):
                break
        maxi = 1 + (S - L) // i
        #return expected, maxi
        return maxi - expected
    print('Case #%d:' % x, doit())
#    print('Case #%d:' % x, K, L, S, keys, tar)
