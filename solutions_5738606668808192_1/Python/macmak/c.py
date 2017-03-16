from math import sqrt

plist = [2]
for n in range(3,100000):
    prime = True
    for p in plist:
        if n % p == 0:
            prime = False
            break
    if prime:
        plist.append(n)

T = int(input())

for case in range(T):
    N,J = map(int,input().split())
    print('Case #',case+1,':',sep='')
    fmstr = '0'+str(N-2)+'b'

    i = 0
    anscnt = 0
    while(anscnt < J):
        cands = '1'+format(i,fmstr)+'1'
        outl = []
        for base in range(2,11):
            candi = int(cands,base)
            #print(candi)
            sqc = sqrt(candi)
            for cd in plist:
                if candi % cd == 0:
                    outl.append(cd)
                    break
                if cd > sqc:
                    break
        if len(outl) == 9:
            print(cands,*outl)
            anscnt += 1
            if anscnt == J:
                break
        if '0' not in cands:
            print('reached counter limit')
            break
        i+=1
