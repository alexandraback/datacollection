import time
##import sys
##sys.setrecursionlimit(10002)
from collections import Counter
snum=["ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"]
scn=[Counter(i) for i in snum]
##print reduce(lambda x,y:x+y,[scn[i] for i in [1,3,5,7,9]])
def solve(s):
    ss=Counter(s)
    res=[0]*10
    res[0]=ss['Z']
    for i in 'ZERO':
        ss[i]-=res[0]
    res[2]=ss['W']
    for i in 'TWO':
        ss[i]-=res[2]
    res[4]=ss['U']
    for i in 'FOUR':
        ss[i]-=res[4]
    res[6]=ss['X']
    for i in 'SIX':
        ss[i]-=res[6]
    res[8]=ss['G']
    for i in 'EIGHT':
        ss[i]-=res[8]

    res[1]=ss['O']
    for i in 'ONE':
        ss[i]-=res[1]
    res[3]=ss['T']
    for i in 'THREE':
        ss[i]-=res[3]
    res[5]=ss['F']
    for i in 'FIVE':
        ss[i]-=res[5]
    res[7]=ss['S']
    for i in 'SEVEN':
        ss[i]-=res[7]

    res[9]=ss['I']
    for i in 'NINE':
        ss[i]-=res[9]
##    print ss
    ans=[str(i)*res[i] for i in range(10)]
    return ''.join(ans)

def main():
    fi=file('as.in')
    fo=file('a.out','w')
    time0=time.time()
    t=int(fi.readline())
    for ti in range(t):
        time1=time.time()
        s=fi.readline()[:-1]
        ans="Case #%d: %s"%(ti+1,solve(s))
        print ans,"%.3f"%(time.time()-time1)
        fo.write(ans+'\n')
    print "%.3f"%(time.time()-time0)
    fi.close()
    fo.close()

if __name__ == '__main__':
    main()
##    import random
##    s=list('abcdefghij'*100)
##    random.shuffle(s)
##    time0=time.time()
##    print solve(s),time.time()-time0
