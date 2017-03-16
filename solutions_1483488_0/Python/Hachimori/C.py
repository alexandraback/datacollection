#!/usr/local/bin/python

def read():
    return map(int,raw_input().split())


def isOk(a,b):
    a = str(a)
    b = str(b)
    for i in range(len(a)):
        if a[i:]+a[:i]==b:
            return True
    return False


def cnt(cur,used,A,B):
    ret = 0
    cur = str(cur)
    for i in range(len(cur)):
        if str(A)<=(cur[i:]+cur[:i])<=str(B) and not used[int(cur[i:]+cur[:i])]:
            used[int(cur[i:]+cur[:i])] = True
            ret += 1
    return ret*(ret-1)/2

    
def work(cases,(A,B)):
    used = [False]*(B+1)

    ans = 0
    for i in range(A,B+1):
        if used[i]:
            continue
        ans += cnt(i,used,A,B)
    print "Case #%d: %d"%(cases,ans)
    

if __name__=="__main__":
    for i in range(int(raw_input())):
        work(i+1,read())
