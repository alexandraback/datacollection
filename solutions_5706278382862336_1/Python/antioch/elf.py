from fractions import gcd
pwr2=[1,2,4,8,16,32,64,128,256,512,1024]
pwr=2048
for i in range(30):
    pwr2.append(pwr)
    pwr*=2
fh=open('/codejam/elf2.in','r')
gh=open('/codejam/elf2.out','w')
T=int(fh.readline())
for num in range(1,T+1):
    s='Case #'+str(num)+': '
    lst=fh.readline().split('/')
    p=int(lst[0])
    q=int(lst[1])
    n=gcd(p,q)
    p=p // n
    q=q // n
    if q not in pwr2:
        s=s+'impossible\n'
        gh.write(s)
        continue
    k=0
    while p<q:
       k+=1
       p*=2
    s=s+str(k)+'\n'
    gh.write(s) 
fh.close()
gh.close()