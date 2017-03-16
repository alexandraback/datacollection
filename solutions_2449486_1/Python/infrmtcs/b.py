f=open("input","r");
ntest=int(f.readline());

for test in range(1,ntest+1):
    pair=f.readline().split();
    m=int(pair[0]);
    n=int(pair[1]);

    a=[];
    for i in range(0,m):
        a.append(f.readline().split());

    r=[-1]*m;
    c=[-1]*n;
    
    for i in range(0,m):
        for j in range(0,n):
            a[i][j]=int(a[i][j]);
            r[i]=max(r[i],a[i][j]);
            c[j]=max(c[j],a[i][j]);

    res="YES";
    for i in range(0,m):
        for j in range(0,n):
            if a[i][j]!=r[i] and a[i][j]!=c[j]:
                res="NO";

    print("Case #",test,": ",res,sep='');
