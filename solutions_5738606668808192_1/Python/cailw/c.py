ps=[2]
for i in range(3,100000,2):
    for p in ps:
        if p*p>i:
            prime=True
            break
        if i%p==0:
            prime=False
            break
    if prime:
        ps.append(i)
n=int(input('N:'))
jamcoin=int(input('J:'))
fo=open('co.txt','w')
print('Case #1:',file=fo)
for i in range(2**(n-1)+1,2**n,2):
    ok=True
    coin=bin(i)[2:]
    proof=[0]*11
    for j in range(2,11):
        num=int(coin,base=j)
        notp=False
        for p in ps:
            if p*p>num:
                break
            if num%p==0:
                notp=True
                proof[j]=p
                break
        if not notp:
            ok=False
            break
    if ok:
        print(coin,*proof[2:11],file=fo)
        jamcoin-=1
        if jamcoin==0:
            break
fo.close()
