#!/usr/bin/python3
# -*- coding: utf-8 -*-

def prepeare():
    global ans
    def is_poly(s):
        return str(s) == ''.join(reversed(str(s)))
    def check(s):
        s = int(s)
        return is_poly(s) and is_poly(s*s)
    ans = []
    for i in range(100):
        if check(i):
            ans.append(str(i))
    for len1 in range(3,52):
        new_ans = []
        for add in range(1,3):
            for x in ans:
                if (len1-len(x))%2==0:
                    s = str(add)+x.center(len1-2,'0')+str(add)
                    if check(s):
                        new_ans.append(s)
        ans.extend(new_ans)
    ans = [int(x)**2 for x in ans]
    ans.sort()

def solve():
    global ans
    A,B = map(int,input().split())
    l=0
    r=len(ans)
    L=r
    while r-l>=0:
        m = (l+r)//2
        if ans[m]>=A:
            r=m-1
            L=m
        else:
            l=m+1
    l=0
    r=len(ans)
    R=-1
    while r-l>=0:
        m = (l+r)//2
        if ans[m]>B:
            r=m-1
        else:
            l=m+1
            R=m
    if R-L+1>0:
        print (R-L+1)
    else:
        print (0)


if __name__=="__main__":
    prepeare()
    T = int(input())
    for t in range(1,T+1):
        print("Case #%d:"%t,end=' ')
        solve()

