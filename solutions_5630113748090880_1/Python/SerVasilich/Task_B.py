fi=open("B-large.in"); fo=open("B-large.out","w")
#fi=open("B-small-attempt0.in"); fo=open("B-small-attempt0.out","w")

from collections import *

def calc(n):
    d=Counter()
    for _ in range(2*n-1):
        for x in map(int,fi.readline().split()):
            d[x]+=1
    return ' '.join([str(x) for x in sorted(d) if d[x]%2])


for T in range(int(fi.readline())):     
    print("Case #"+str(T+1)+":",calc(int(fi.readline())),file=fo)

fi.close()
fo.close()
print("OK")