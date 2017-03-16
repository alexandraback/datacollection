from bisect import bisect_left,bisect_right
f=open('/Users/pruthvikarreddy/Downloads/D-small-attempt0.in').read()
o = open('/Users/pruthvikarreddy/Downloads/outd.txt','w')
v=f.splitlines()

def nextval(a, key):
    i = bisect_left(a, key)
    if i == len(a):
        return None
    return a[i]
def prevval(a, key):

    i = bisect_right(a, key)
    return a[0]

l=1
for ix,x in enumerate(f.splitlines()[1::3]):
    a=sorted(float(val) for val in v[l+1].split(' '))
    
    b=sorted(float(val) for val in v[l+2].split(' '))
    br=list(reversed(b))
    c=0
    for num in a:
        ans=nextval(b,num)
        if ans:
            b.remove(ans)
        else:
            num2=prevval(b,num)
            b.remove(num2)
            c+=1
    dc=0
    for num in br:
        if a[-1]>num:
            a.remove(a[-1])
            dc+=1
        elif a[0]<num:
            a.remove(a[0])
            
        else:
            dc+=len(a)
        
    o.write('Case #'+str(ix+1)+': '+str(dc)+' '+str(c)+'\n')
    l+=3
