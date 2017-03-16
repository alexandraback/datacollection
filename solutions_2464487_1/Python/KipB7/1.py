import math as m


filename = r'c:\g\a\1a.txt'
#filename = r'c:\g\a\A-small-attempt0.in.txt'
filename = 'A-large.in.txt'
foutname=r'c:\g\a\1a-out.txt'

FILE = open(filename)
FOUT = open(foutname,"w")
T = int(FILE.readline())

def p1(r,nrings): #r=radius of white, t=milliliters (pi square cm) of paint
    return nrings*(2*(r+nrings)-1) #will multiply by pi
def p1nrings1(r,t):
    for n in range(2000):
        if p1(r,n)>t: return n-1
    return None
def p1nrings2(r,t):
    n,nadd,adds=1,1,0
    sanity=0
    while 1:
        sanity += 1
        if sanity>1000000:
            print "fail!"
            return None
        #print sanity,(n,nadd,adds),p1(r,n)-t
        
        if p1(r,n)>t:
            if nadd==1: return n-1
            n -= nadd
            nadd = nadd//2
            n += nadd
            adds=1
        else:
            n += nadd
            adds += 1
            if adds>2: nadd,adds = nadd*2,0
    return None

for i in range(1,T+1):
    rawline = FILE.readline().split(' ')
    a,b = int(rawline[0]), int(rawline[1])
    #print "Case #" + str(i)+": begin r=",a," t=",b

    msg = 'Case #' + str(i) + ': ' + str(p1nrings2(a,b))
    if i%10==1: print msg
    FOUT.write(msg + "\n")
FOUT.close()
