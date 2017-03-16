#!/usr/bin/env python


N = 16
J = 50


vis = [True] * (2**26)
prime = []

vis[0] = False
vis[1] = False

for i in xrange(2**26):
    if vis[i]:
        prime.append(i)
        j = i + i
        while j < 2**26:
            vis[j] = False
            j += i

def toBase(K, N):
    res = 0
    b = 1
    while K > 0:
        if K%2 == 1:
            res += b
        b *= N
        K /= 2

    return res


def getFactor(x):
    for i in prime:
        if i * i > x:
            break

        if x % i == 0:
            return i

    return -1

def test(K):
    res = []
    for i in xrange(2,11):
        t = toBase(K, i)
        x = getFactor(t)
        if x > 0:
            res.append(x)

    return res


ans = []

for i in xrange (2**14, 2**15):
    res = test(2*i + 1)
    if len(res) == 9:
        ans.append( (i,res) )

    if len(ans) == J:
        break


print "Case #1:"

for x in ans:
    i, res = x
    print "{0:b}".format(i), " ".join( [str(r) for r in res] )


