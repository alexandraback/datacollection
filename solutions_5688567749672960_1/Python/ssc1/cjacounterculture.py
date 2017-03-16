def r(n):
    return int(str(n)[::-1])
f = open("al.in")
fo=open('out','w')
def raw_input():
    return f.readline().strip()
def g(n):
    if n<21:
        return n
    s=str(n)
    x=10**(len(s)//2)
    y=n//x*x+1
    #print n,y
    e=r(y)
    if r(y)>=y or n<y:
        return g(n-x+1)+x-1
    else:
        return g(r(y))+n-y+1
for z in range(int(raw_input())):
    n= int(raw_input())
    fo.write("Case #%d: %d\n" % (z + 1,g(n)))
'''
l=[1]*(500)
for i in range(2,len(l)):
    re=r(i)
    if i%10!=0 and re<i:
        l[i]=min(l[i-1],l[re])+1
    else:
        l[i]=l[i-1]+1
    b=g(i)
    if b!=l[i]:
        print i,l[i],b
'''
print "d"