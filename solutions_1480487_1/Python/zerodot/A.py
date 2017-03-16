def parse():
    f=open('A-large.in','r')
    text=f.read()
    f.close()
    return (line for line in text.splitlines())

def cases():
    p=parse()
    cases=next(p)
    tr=[]
    for e in p:
        list=[float(i) for i in e.split()]
        tr.append(list[1:])
    return tr

def safenum(case):
    total=sum(case)
    d={}
    for i in case:
        d[i]=case.count(i)
    keys=sorted(d.keys())
    while len(d)>=1:
        if len(keys)==1: return keys[0]+total/d[keys[0]]
        diff=keys[1]-keys[0]
        if diff*d[keys[0]]>total: return keys[0]+total/d[keys[0]]
        total-=diff*d[keys[0]]
        d[keys[1]]+=d[keys[0]]
        del d[keys[0]]
        keys=keys[1:]
    print("problem")

def solve(case):
    total=sum(case)
    s=safenum(case)
    li=[str(100*max(s-i,0)/total) for i in case]
    return ' '.join(li)

if __name__=='__main__':
    e=enumerate(cases(), start=1)
    f=open('out.txt','w')
    for (n,c) in e:
            f.write('Case #'+str(n)+': '+solve(c)+'\n')
    f.close()
