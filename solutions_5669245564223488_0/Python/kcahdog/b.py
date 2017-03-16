def check(s):
    b=s[0]
    #global gd
    for i in s[1:-1]:
    #if(not(ord(s[i])- ord(s[i-1])==0 or ord(s[i])- ord(s[i-1])==1)):
        if(gd.has_key(i) and i!=b):
            return False
        else:
            gd[i]=True
            b=i
    return True

mod=10**9+7

def fact(n):
    ans=1
    
    for i in xrange(1,n+1):
        ans*=i
        if(ans>mod):
            ans%=mod
    return ans

for qq in xrange(1,1+int(raw_input())):
    print 'Case #%d:'% qq,
    gd={}
    n=int(raw_input())
    arr=[]
    inp=raw_input().split()
    flag=False
    for s in inp:
        if(not check(s)):
            print 0
            flag=True
            break
        else:
            arr.append(s[0]+s[-1])
    if(flag):
        continue
    arr.sort()
    #print 'Hello 1'
    
    
    for i in xrange(1,len(arr)):
        if(ord(arr[i-1][1]) > ord(arr[i][0]) ):
            print 0
            flag=True
            break
    if(flag):
        continue
    ans=1
    cnt=1
    d={}
    #print 'hello 2'
    for i in arr:
        if(d.has_key(i)):
            d[i]+=1
        else:
            d[i]=1
    
    cnt=1
    ans=1
    #print d
    for i in d.keys():
        ans*=fact(d[i])
        ans%=mod
        
    for i in xrange(1,len(arr)):
        if(arr[i][0]!=arr[i-1][1]):
            cnt+=1
    ans*=fact(cnt)
    ans%=mod
    print ans
        
            
        
        
            
