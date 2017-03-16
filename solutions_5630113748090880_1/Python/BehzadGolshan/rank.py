from collections import Counter;

n = int(raw_input())
for itt in xrange(n):
    size = int(raw_input())
    obs = []
    for i in xrange(2 * size - 1):
        obs = obs + raw_input().strip().split()
    # solving the problem
    temp = Counter(obs)
    res = []
    for e in temp:
        if temp[e] % 2 == 1:
            res.append(int(e))
    res_str = '';
    for e in sorted(res):
        res_str = res_str + ' ' + str(e)
    print 'Case #' + str(itt + 1) + ':' + res_str#str(num * 2)
