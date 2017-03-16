fh=open('/codejam/elf1.in','r')
gh=open('/codejam/elf1.out','w')
T=int(fh.readline())
for num in range(1,T+1):
    s='Case #'+str(num)+': '
    lst=fh.readline().split('/')
    p=int(lst[0])
    q=int(lst[1])
    if q not in [1,2,4,8,16,32,64,128,256,512,1024,2048,4096]:
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