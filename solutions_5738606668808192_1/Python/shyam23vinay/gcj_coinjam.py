def res(n):
    i=2
    while(i<=10000):
        if(n%i==0):
            return i
        i=i+1
    return 1

def nxt(a):
    l=len(a)
    s=['1']*l
    k=l-2
    index=1
    while(k>=1):
        if(a[k]=='1'):
            s[k]='0'
        else:
            s[k]='1'
            index=k
            break
        k=k-1
    index=index-1
    while(index>=1):
        s[index]=a[index]
        index=index-1
    st=''
    for e in s:
        st=st+e
    return st

fin=file("C-large-attempt0.in","r")
fout=open("C-large-attempt0.out","w")
fin=fin.read()
fin=fin.split('\n')
t=int(fin[0])
for tc in range(1,t+1):
    n,j=fin[tc].split(" ")
    n=int(n)
    j=int(j)
    ans=''
    ans=ans+"Case #"+str(tc)+":\n"
    s='1'+'0'*(n-2)+'1'
    k=1
    while(k<=j):
        a=[]
        flag=0
        ten=0
        for p in range(0,n):
            ten=ten*10+int(s[p])
        a.append(ten)
        for x in range(2,11):
            temp=0
            for p in range(0,n):
                temp=temp*x+int(s[p])
            temp_res=res(temp)
            if(temp_res==1):
                flag=1
                break
            else:
                a.append(temp_res)
        if(flag==0):
            for p in range(0,len(a)):
                ans=ans+ str(a[p])+" "
            ans=ans+"\n"
            k=k+1
        s=nxt(s)
fout.write(ans)
fout.close()

