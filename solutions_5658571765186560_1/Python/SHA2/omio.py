'''
Created on Apr 11, 2015

@author: Incognito
'''
gab="GABRIEL"
ric="RICHARD"
T=int(raw_input())
for j in range(T):
    x,r,c=map(int,raw_input().split(" "))
#     print x,r,c
    size=r*c
    if x==1:
        print "Case #"+`j+1`+":", gab
        continue
    if x>=7:
        print "Case #"+`j+1`+":", ric
        continue
    if x==2:
        if (r*c) % 2==0:
            print "Case #"+`j+1`+":", gab
            continue
        else:
            print "Case #"+`j+1`+":", ric
            continue    
    if x==3:
        if size % x !=0 or r==1 or c==1:
            print "Case #"+`j+1`+":", ric
            continue
        else:
            print "Case #"+`j+1`+":", gab
            continue
    if x==4:
        if size % x !=0 or r<=2 or c<=2:
            print "Case #"+`j+1`+":", ric
            continue
        else:
            print "Case #"+`j+1`+":", gab
            continue
    if x==5:
        if size % x !=0 or r<=2 or c<=2 or size==15:
            print "Case #"+`j+1`+":", ric
            continue
        else:
            print "Case #"+`j+1`+":", gab
            continue
    if x==6:
        if size % x !=0 or r<=3 or c<=3:
            print "Case #"+`j+1`+":", ric
            continue
        else:
            print "Case #"+`j+1`+":", gab
            continue
    

