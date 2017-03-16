f = open('a.in','r')
g = open('b.out','w')
T = int(f.readline())
for x in range(T):
    temp = map(int,f.readline().split(' '))
    r = temp[0]
    t = temp[1]
    n = int(.25*((8*t + (2*r-1)**2)**.5 - (2*r - 1)))
    writ = 'Case #'+str(x+1)+': '+str(n)+'\n'
    g.write(writ)
    print writ
f.close()
g.close()
