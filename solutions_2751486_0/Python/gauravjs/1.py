def parse():
    with open('A-small-attempt0.in','r') as f:
        cases=int(f.readline())
        for i in range(cases):
            a,b=f.readline().split(' ')
            b=int(b)
            ans=answer(a,b)
            print 'Case #'+str(i+1)+': '+str(ans)

vowels=['a','e','i','o','u']
def answer(a,b):
    cons=0
    l=[0]*len(a)
    for i in xrange(len(a)):
        if a[i] not in vowels:
            cons=min(b,cons+1)
        else:
            cons=0
        if cons==b:
            l[i]=1
    return num2(l,b)

def num2(l,b):
    last=len(l)
    s=0
    for i in range(len(l))[::-1]:
        if l[i]==1:
            s=s+(last-i)*(i+2-b)
            last=i
    return s

parse()
