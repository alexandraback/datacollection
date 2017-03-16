#fi=open("C-large.in"); fo=open("C-large.out","w")
fi=open("C-small-attempt0.in"); fo=open("C-small-attempt0.out","w")

def div(a):
    for i in range(2,int(a**0.5)+1): 
        if a%i==0: return str(i)
    return ""


def fnd(n,k):
    kil=0
    for i in range(2**(n-2)):
        s=bin(i)[2:].zfill(n-2).join(['1','1'])
        l=[div(int(s,b)) for b in range(2,11)]
        if "" in l: continue
        print(s,file=fo)  
        fo.flush()
        k-=1
        kil+=1
        if k==0: break
    print(kil,file=fo)

def fnd2(n,k):
    kil=0
    print(n)
    for i1 in range(n-5):
      for i2 in range(1,n-4-i1):
        for i3 in range(n-4-i1-i2):
          for i4 in range(1,n-3-i1-i2-i3):
            for i5 in range(n-3-i1-i2-i3-i4):
              for i6 in range(1,n-2-i1-i2-i3-i4-i5):
                for i7 in range(n-2-i1-i2-i3-i4-i5-i6):
                  for i8 in range(1,n-1-i1-i2-i3-i4-i5-i6-i7):
                    i9=n-1-i1-i2-i3-i4-i5-i6-i7-i8
                    s='1'+'0'*i1+'1'*i2+'0'*i3+'1'*i4+'0'*i5+'1'*i6+'0'*i7+'1'*i8+'0'*i9+'1'
                    print(s)                    
                    l=[div(int(s,b)) for b in range(2,11)]
                    if ['3','2','3','2','7','2','3','2','3']!=l: continue
                    print(s,file=fo)  
                    fo.flush()
                    k-=1
                    kil+=1
                    if k==0: break
    print(kil,file=fo)
    
for T in range(int(fi.readline())):     
    print("Case #"+str(T+1)+":",file=fo)
    n,j=map(int,fi.readline().split())    
    fnd2(n,j)

fi.close()
fo.close()
print("OK")