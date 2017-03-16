import sys
from sets import Set

def readInts():
    return map(int, sys.stdin.readline().strip().split())

def solve(x,y):

    ss = Set([])
    
    q = [(0,0,1,'')]
    while q:
        t = q.pop()

        if t[0]==x and t[1]==y:
            return t[3]

        e = (t[0]+t[2], t[1], t[2]+1, t[3]+'E')
        w = (t[0]-t[2], t[1], t[2]+1, t[3]+'W')
        s = (t[0], t[1]-t[2], t[2]+1, t[3]+'S')
        n = (t[0], t[1]+t[2], t[2]+1, t[3]+'N')

        if abs(e[0])<=100 and abs(e[1])<=100 and len(e[3])<=500:
            aa = (e[0], e[1], e[2])
            if aa not in ss: 
                q.append(e)
                ss.add(aa)
        if abs(w[0])<=100 and abs(w[1])<=100 and len(w[3])<=500:
            aa = (w[0], w[1], w[2])
            if aa not in ss:
                q.append(w)
                ss.add(aa)
        if abs(s[0])<=100 and abs(s[1])<=100 and len(s[3])<=500:
            aa = (s[0], s[1], s[2])
            if aa not in ss:
                q.append(s)
                ss.add(aa)
        if abs(n[0])<=100 and abs(n[1])<=100 and len(n[3])<=500:
            aa = (n[0], n[1], n[2])
            if aa not in ss:
                q.append(n)
                ss.add(aa)
    
T = readInts()[0]

for case in xrange(1, T+1):
    X,Y = readInts()
    
    print 'Case #%d: %s' % (case, solve(X,Y))

