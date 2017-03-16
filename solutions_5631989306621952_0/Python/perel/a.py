import time
##import sys
##sys.setrecursionlimit(10002)
from collections import deque
def solve(s):
    ans=deque([s[0]])
    for si in s[1:]:
        if si>=ans[0]:
            ans.appendleft(si)
        else:
            ans.append(si)

    return ''.join(ans)

def main():
    fi=file('al.in')
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
