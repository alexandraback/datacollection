import sys
import time

pat=[]
for i in range(0,30):
    pat.append([])
print(pat)
res=[]

pat[0]=[0];

for l in range(1,27):
    for i in pat[l-1]:
        for c in range(0,10):
            j=i*10+c;
            if j>0:
                if l==1:
                    x=str(j*j)
                else:
                    x=str(int(str(i)+(str(j)[::-1]))**2);
                if x==x[::-1]:
                    res.append(int(x));

                x=str(int(str(j)+(str(j)[::-1]))**2);
                if x==x[::-1]:
                    pat[l].append(j);
                    res.append(int(x));

res.sort()

def count(x):
    c=0
    for i in res:
        if i<=x:
            c+=1
    return c

f=open("input","r");
ntest=int(f.readline());

for test in range(1,ntest+1):
    z=f.readline().split()
    a=int(z[0])
    b=int(z[1])
    
    print("Case #",test,": ",count(b)-count(a-1),sep='');
