#!/usr/local/bin/python


def read():
    return map(int,raw_input().split()[1:])


def calc(idx,scores):
    X = sum(scores)
    L = 0
    R = 1<<30
    for loop in range(100):
        mid = (L+R)/2.0
        total = 0
        for i in range(len(scores)):
            total += max(0,mid-scores[i])
        if total<X:
            L = mid
        else:
            R = mid
    return 100*(max(0,(L-scores[idx])/X))


def work(cases,scores):
    ans = []
    
    for i in range(len(scores)):
        ans.append(calc(i,scores))

    print "Case #%d: "%(cases)+" ".join(map(str,ans))
    

if __name__=="__main__":
    for i in range(int(raw_input())):
        work(i+1,read())

