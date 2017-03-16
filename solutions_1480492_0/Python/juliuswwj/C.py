# C

import sys

def getline():
    return sys.stdin.readline().strip()
    
def ctime(c):
    mt = -1
    mi = 0
    for i in range(len(c)-1):
        if c[i][0] <= c[i+1][0]: continue
        t = (c[i+1][1] - c[i][1] - 5) / (c[i][0] - c[i+1][0])
        if mt < 0 or mt > t:
            mt = t
            mi = i
    return [mt, mi]

def shift(l, r, il, t, tl):
    # in [t, t+tl] time, can il do shift?
    
    pr = list()
    for i in range(len(r)):
        pr.append( (r[i][0] - l[il][0], r[i][1] - l[il][1]) )
    
    for i in range(len(r)):
        if pr[i][1]<=-5 and pr[i][0]>0 and pr[i][0]*tl + pr[i][1]<=-5:continue
        if pr[i][1]>=5 and pr[i][0]<0 and pr[i][0]*tl + pr[i][1]>=5:continue
        return -tl
    
    r.append(l[il])
    l.pop(il)
        
    return tl
    
def dorun(l, dt):
    for i in range(len(l)):
        l[i][1] += l[i][0] * dt
    
def run(cars):
    l = list()
    r = list()
    for i in range(len(cars)):
        if cars[i][0] == 'L':
            l.append( [float(cars[i][1]), float(cars[i][2])] )
        else:
            r.append( [float(cars[i][1]), float(cars[i][2])] )
    
    t = 0
    while True:
        # sort by position
        l = sorted(l, key=lambda x: x[1])
        r = sorted(r, key=lambda x: x[1])
        (tl, il) = ctime(l)
        (tr, ir) = ctime(r)
        
        #print l, r, tl, tr
        if tl<0 and tr<0: break
        
        dt = 0
        if tl>=0 and tr>=0:
            if tr<tl:
                dt = shift(r, l, ir, t, tr)
            else:
                dt = shift(l, r, il, t, tl)
        elif tl>=0:
            dt = shift(l, r, il, t, tl)
        elif tr>=0:
            dt = shift(r, l, ir, t, tr)
        
        if dt<=0: return t - dt
        dorun(l, dt)
        dorun(r, dt)
        t += dt

    return 'Possible'    

n = int(getline())

for id in range(1, n+1):
    print 'Case #%d:' % id,
    
    n = int(getline())
    cars = list()
    for i in range(n):
        cars.append(getline().split(' '))
    
    print run(cars)
    
