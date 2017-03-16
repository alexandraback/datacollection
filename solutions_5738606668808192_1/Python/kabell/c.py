pp = 2**31
d = [2,3,5,7,11,13,17,19,23,29,31,37,41,47]

pocet=0
for i in range(pp,pp+1000000):
    if(pocet==500):
        break
    dd = [];
    for j in range(2,11):
        p=i
        x=0
        pos=0
        s = ""
        while(p>0):
            s=str(p%2)+s
            x+=(j**pos)*(p%2)
            pos+=1
            p//=2

        for k in d:
            if x%k==0:
                dd.append(k)
                break
    if len(dd)==9 and s[31]=='1':
        pocet+=1;
        print s ,
        for j in range(0,9):
            print dd[j],
        print
        



