def r(n):
    return int(str(n)[::-1])
f = open("a0.in")
fo=open('out','w')
def raw_input():
    return f.readline().strip()
l=[1]*(10**6+1)
for i in range(2,len(l)):
    re=r(i)
    if i%10!=0 and re<i:
        l[i]=min(l[i-1],l[re])+1
    else:
        l[i]=l[i-1]+1
for z in range(int(raw_input())):
    n= int(raw_input())
    
    fo.write("Case #%d: %d\n" % (z + 1,l[n]))
