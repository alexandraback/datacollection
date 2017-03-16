from random import randint
J = 16
ma = dict()
while len(ma) < 50:
    x = ['1']
    for i in xrange(J - 2):
        x.append(str(randint(0, 1)))
    x.append('1')
    s = "".join(x)
    ans = []
    for i in xrange(2, 11):
        a = int(s, base=i)
        for j in xrange(2, min(1000, a)):
            if a % j == 0:
                #print a, j
                ans.append(j)
                break
    if len(ans) == 9:
        ma[s] = ans

for k, v in ma.iteritems():
    print k + " " + " ".join([str(x) for x in v])

