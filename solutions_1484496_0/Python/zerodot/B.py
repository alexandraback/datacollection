def parse():
    f=open('C-small-attempt0.in','r')
    text=f.read()
    f.close()
    lines=(e for e in text.splitlines())
    next(lines) #cases
    return [[int(e) for e in line.split()][1:] for line in lines]

def subsets(case):
    for w in range(2**len(case)):
        tr=[]
        i=0
        while w>0:
           if w%2==1: tr.append(case[i])
           w//=2
           i+=1
        yield tr

def solve(case):
    d={}
    for e in subsets(case):
        s=sum(e)
        if s in d:
            return ' '.join([str(el) for el in d[s]])+'\n'+' '.join([str(el) for el in e])+'\n'
        d[s]=e

if __name__=='__main__':
    f=open('out.txt','w')
    e=enumerate(parse(),start=1)
    for (n,c) in e:
        f.write("Case #"+str(n)+":\n"+solve(c))
    f.close()
