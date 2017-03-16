#!/usr/bin/python
inf = open('in', 'r')

strings = inf.read().split("\n")
n = int(strings[0])
for i in range(1,n+1):
    (a, b) = strings[2*i-1].split(' ')
    a = int(a)
    b = int(b)
    probs = strings[2*i].split(' ')
    pr = [float(p) for p in probs]
    result = 1 + b + 1
    rest = 1
    wrong = 0
    for j in range(1, a + 1):
        wrong = wrong + rest * (1 - pr[j - 1])
        cur_result = wrong * (a + 2 * b - 2 * j + 2) + (1 - wrong) * (a + b - 2 * j + 1)
        rest = rest * pr[j - 1]
        if cur_result < result:
            result = cur_result
    print "Case #%d: %f" % (i, result)
    i += 1

inf.close()
