'''
Created on Apr 10, 2015

@author: Mohammad
'''
T=int(raw_input())
for j in range(T):
    inp=raw_input().split(" ")
    max=inp[0]
    str=inp[1]
    res=0
    shy=0
    i=0
    total=0
    for x in str:
        if(i>total):
            temp=i-total
            res+=temp
        else:
            temp=0
        total+=temp+int(x)
        i+=1
    print "Case #"+`j+1`+":",res