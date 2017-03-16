from collections import Counter as ct
from itertools import permutations
for z in range(int(raw_input())):
    n=int(raw_input());t=0
    l=[raw_input().split() for _ in range(n)]
    a=ct(map(lambda x:x[0],l));b=ct(map(lambda x:x[1],l))
    fst=set();snd=set();newl=[]
    for i in l:
        if a[i[0]]==1 or b[i[1]]==1:
            fst.add(i[0]);snd.add(i[1])
        else:
            newl.append(i)
    l=newl;newl=[]
    for i in l:
        if i[0] in fst and i[1] in snd:
            t+=1
        else:
            newl.append(i)
    l=newl;newl=[]
    while len(l)>0:
        s1=set();s2=set();tp=1
        s1.add(l[0][0]);s2.add(l[0][1])
        l=l[1:];tp=1
        while True:
            newl=[]
            for i in l:
                if i[0] in s1 or i[1] in s2:
                    tp+=1
                    if i[0] not in fst:
                        s1.add(i[0])
                    if i[1] not in fst:
                        s2.add(i[1])
                else:
                    newl.append(i)
            if l==newl:
                t+=tp/2;break
            l=newl
    print "Case #{:d}: {}".format(z+1,t)