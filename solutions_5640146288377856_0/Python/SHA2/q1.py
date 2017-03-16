'''
Created on May 10, 2015

@author: Incognito
'''
    
T=int(raw_input())
for j in range(T):
    r,c,w=map(int,raw_input().split(" "))
    print r,c,w
    count=0
    total=0
    while total<c:
        total+=w
        if total>c:
            total-=w
            break
        count+=1
    count*=r
    if total==c:
        count+=w-1
    else:
        count+=w
    
    print "Case #"+`j+1`+":",count