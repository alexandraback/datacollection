import sys
wt=sys.stdout.write

def count(i,e):
    global cls
    c=0
    for k in cls[i]:
        if e==k:c+=1
        else:c+=count(k,e)
    return c

def test():
    for m in xrange(1,C+1):
        for n in xrange(1,C+1):
            if count(m,n)>1:
                return True
    return False

f=open('a1.in')
NUM=int(f.readline())
i=0
while i<NUM:
    i+=1
    wt('Case #%d: '%i)

    C=int(f.readline())
    cls=[]
    cls.append([])
    for c in xrange(C):
        cls.append([])
        l=map(int,f.readline().split(' '))
        cls[c+1]+=l[1:]
    
    if test(): print "Yes"
    else: print "No"
