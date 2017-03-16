__author__ = 'Arwin'
from itertools import product

fn = 'C-large.in'
f = open(fn)
ansf = open("ans.txt", "w")

T = int(f.next())
for case in xrange(1, T + 1):
    jpsk = map(int,f.next().strip().split())
    s= jpsk[2]
    k= jpsk[-1]
    ans= jpsk[0]*jpsk[1]*min(s,k)
    ansf.write('Case #{0}: {1}\n'.format(case,ans))
    J= range(1,jpsk[0]+1)
    P= range(1,jpsk[1]+1)
    S= range(1,jpsk[2]+1)
    Dps={}
    Djs={}
    for cbn in product(P,S):
        Dps[cbn]=0
    for cbn in product(J,S):
        Djs[cbn]=0
    for idx,cbn in enumerate(product(J,P)):
        c=0
        Djp=0
        while c<s and Djp<k:
            thisN= S[(c+idx+J.index(cbn[0]))%s]
            if Dps[(cbn[1],thisN)]<k and Djs[(cbn[0],thisN)]<k:
                ansf.write(' '.join(map(str,[cbn[0],cbn[1],thisN])))
                ansf.write('\n')
                Dps[(cbn[1],thisN)]+=1
                Djs[(cbn[0],thisN)]+=1
                Djp+=1
            c+=1
ansf.close()