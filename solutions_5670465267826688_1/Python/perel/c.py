import time
def init():
    global res
    s=['1','i','j','k']
    res={}
    res[('1','1')]='1'
    for i in ['i','j','k']:
        res[(i,i)]='-1'
        res[('1',i)]=i
        res[(i,'1')]=i
    res[('i','j')]='k';res[('j','i')]='-k'
    res[('i','k')]='-j';res[('k','i')]='j'
    res[('j','k')]='i';res[('k','j')]='-i'
    for i in s:
        for j in s:
            res[(i,'-'+j)]=('-'+res[(i,j)]) if len(res[(i,j)])==1 else res[(i,j)][-1]
            res[('-'+i,j)]=('-'+res[(i,j)]) if len(res[(i,j)])==1 else res[(i,j)][-1]
            res[('-'+i,'-'+j)]=res[(i,j)][-1]
    #print res

def calc(s):
    global res
    r='1'
    for i in s:
        r=res[(r,i)]
    return r

def test(s):
    global res
    r='1'
    l=['i','j','k']
    lc=0
    for i in s:
        r=res[(r,i)]
        if l[lc]==r:
            lc+=1
            r='1'
            if lc==3:
                return True
    return False

def test1(s):
    global res
    r='1'
    l=['i','j','k']
    lc=0
    for i in range(len(s)):
        r=res[(r,s[i])]
        if l[lc]==r:
            lc+=1
            r='1'
            if lc==3:
                return calc(s[i+1:])=='1'
    return False

def solve(l,x,s):
    r=calc(s)
    if r=='-1' and x%2==1:
        if (x==1 and test(s)) or (x>=3 and test(s*3)):
            return 'YES'
        else:
            return 'NO'
    elif r not in ('1','-1') and x%4==2:
        if len(set(s))>1 and (x>=6 or test(s*2)):
            return 'YES'
        else:
            return 'NO'
    else:
        return 'NO'

def main():
    init()
    fi=file('cl.in')
    fo=file('c.out','w')
    time0=time.time()
    t=int(fi.readline())
    for ti in range(t):
        time1=time.time()
        l,x=map(int,fi.readline().split())
        s=fi.readline()[:-1]
        ans="Case #%d: %s"%(ti+1,solve(l,x,s))
        print ans,"%.3f"%(time.time()-time1)
        fo.write(ans+'\n')
    print "%.3f"%(time.time()-time0)
    fi.close()
    fo.close()

if __name__ == '__main__':
    main()
