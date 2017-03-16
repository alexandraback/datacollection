#!/usr/local/bin/python


def read():
    v = map(int,raw_input().split())
    N,S,p,val = v[0],v[1],v[2],v[3:]
    return S,p,val


def work(cases,(nSupr,atLeast,val)):
    ans = 0
    for i in range(len(val)):
        if val[i]<atLeast:
            continue

        if atLeast-(val[i]-atLeast)/2==2 and nSupr>0:
            ans += 1
            nSupr -= 1
        elif atLeast-(val[i]-atLeast)/2<=1:
            ans += 1            

    print "Case #%d: %d"%(cases,ans)


if __name__=="__main__":
    for i in range(int(raw_input())):
        work(i+1,read())
