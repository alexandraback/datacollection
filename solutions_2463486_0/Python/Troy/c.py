fin = open("C-small-attempt0.in")
fout = open("C-small-attempt0.out", "w")
line = fin.readlines()
fin.close()
T = int(line[0])
ca = 0
mx = 10**100

num = []
ten = [1]
for i in xrange(1, 52):
    ten.append(ten[i-1]*10)
#print ten

def dfs(tl, tr, x, s):
    #print tl, tr, x, s
    if (s >= 10):
        return
    if (tl < tr):
        if (x):
            #print x, x**2
            num.append(x**2)
        return
    if (tr > 0):
        dfs(tl-1, tr+1, x, s)
    for i in xrange(1, 3):
        if (tr == 0 and i == 0):
            continue
        x += ten[tl] * i
        s += i * i
        if (tl != tr):
            x += ten[tr] * i
            s += i * i
        dfs(tl-1, tr+1, x, s)

        x -= ten[tl] * i
        s -= i * i
        if (tl != tr):
            x -= ten[tr] * i
            s -= i * i
    return

from pprint import pprint
def pre_init():
    num.append(10**100)
    num.append(9)
    num.append(0)
    for nlen in xrange(1, 52):
        dfs((nlen-1), 0, 0, 0)
        #print len(num), nlen
    num.sort()
    #print len(num)
    #pprint(num)

pre_init()
from bisect import *
def solve(p):
    ret = bisect_right(num, p)
    if (num[ret] == p):
        ret += 1
    return ret
    
for _ in xrange(T):
    a = map(int, line[_+1].split(' '))
    l = a[0]
    r = a[1]
    ans = solve(r) - solve(l-1)
    ca += 1
    print >>fout, "Case #%d: %d" % (ca, ans)
fout.close()
