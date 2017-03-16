import random

N = 32
J = 500

ans = []

while len(ans) < J:
    s = '1' + ''.join([random.choice('01') for i in xrange(N - 2)]) + '1'
    res = [s]

    for i in xrange(2, 10 + 1):
        t = int(s, i)
        for i in xrange(2, min(t, 5000)):
            if t % i == 0:
                res.append(i)
                break
        else:
            break

    if len(res) == 10:
        ans.append(res)


print 'Case #1:'
for item in ans:
    print ' '.join(map(str, item))

