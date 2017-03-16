fi=open("C-large.in"); fo=open("C-large.out","w")
#fi=open("C-small-attempt0.in"); fo=open("C-small-attempt0.out","w")

def div(a):
    for i in [2,3,5,7]: 
        if a%i==0: return i
    return 0

def fnd2(n,k):
    for i1 in range(n-3):
        for i2 in range(n-3-i1):
            i3=n-4-i1-i2
            s='1'+'0'*i1+'1'+'0'*i2+'1'+'0'*i3+'1'
            if k==0: break                    
            l=[div(int(s,b)) for b in range(2,11)]
            if 0 in l: continue
            print(s,' '.join(map(str,l)),file=fo)
            k-=1 
    return k

def fnd3(n,k):
    for i1 in range(n-4):
        for i2 in range(n-4-i1):
            for i3 in range(n-4-i1-i2):
                i4=n-5-i1-i2-i3
                s='1'+'0'*i1+'1'+'0'*i2+'1'+'0'*i3+'1'+'0'*i4+'1'
                if k==0: break                    
                l=[div(int(s,b)) for b in range(2,11)]
                if 0 in l: continue
                print(s,' '.join(map(str,l)),file=fo)
                k-=1    
    return k

def fnd4(n,k):
    for i1 in range(n-5):
        for i2 in range(n-5-i1):
            for i3 in range(n-5-i1-i2):
                for i4 in range(n-5-i1-i2-i3):
                    i5=n-6-i1-i2-i3-i4
                    s='1'+'0'*i1+'1'+'0'*i2+'1'+'0'*i3+'1'+'0'*i4+'1'+'0'*i5+'1'
                    if k==0: break                    
                    l=[div(int(s,b)) for b in range(2,11)]
                    if 0 in l: continue
                    print(s,' '.join(map(str,l)),file=fo)
                    k-=1                    
    return k

def fnd(n,k):
    for i in range(2**(n-2)):
        s=bin(i)[2:].zfill(n-2).join(['1','1'])
        if s.count('1')<7: continue
        if k==0: break
        l=[div(int(s,b)) for b in range(2,11)]
        if 0 in l: continue
        print(s,' '.join(map(str,l)),file=fo)  
        k-=1
        
for T in range(int(fi.readline())):     
    print("Case #"+str(T+1)+":",file=fo)
    n,j=map(int,fi.readline().split())    
    j=fnd2(n,j)
    j=fnd3(n,j)
    j=fnd4(n,j)
    fnd(n,j)

fi.close()
fo.close()
print("OK")