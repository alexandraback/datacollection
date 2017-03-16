from mpmath import *
mp.dps=1600
f = open('a.in','r')
g = open('b.out','w')
T = int(f.readline())
for x in range(T):
    temp = map(int,f.readline().split(' '))
    r = temp[0]
    t = temp[1]
    a = mpf((mpf(8*t)+mpf((2*r-1)**2))**.5) - mpf(2*r-1)
    n = int(mpf(.25)*a)
    writ = 'Case #'+str(x+1)+': '+str(n)+'\n'
    g.write(writ)
f.close()
g.close()
