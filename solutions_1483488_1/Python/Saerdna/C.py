import os,sys

def GetCount(value,A,B):
    l = len(str(value))
    vis = {}
    tmp = 0
    for i in xrange(1,l):
        POW = pow(10,l-i)
        now = (value%POW)*pow(10,i) + value/POW
        if now>value and now<=B and not vis.has_key(now):
            vis[now] = 1
            tmp += 1
    return tmp
if __name__ == '__main__':
    T = int(raw_input())
    for tt in xrange(0,T):
        A,B = map(int,raw_input().split(' '))
        ans = 0
        for i in xrange(A,B):
            det = GetCount(i,A,B)
            ans += det
        print "Case #%d: %d" %(tt+1,ans)
