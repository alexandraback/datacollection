import string
import  collections
import  itertools
fname = 'C:\Users\itocar\Downloads\C-small-attempt3.in'

f = open(fname)

ln = f.readlines()

t = int(ln[0])

case_num = 1
for l in ln[1:]:
    res = []
    j,p,s,k = [int(xx) for xx in l.split()]
    sn1= collections.defaultdict(int)
    sn2= collections.defaultdict(int)
    sn3= collections.defaultdict(int)
    while True:
        k1m,k2m,k3m = k,k,k
        cand = (0,0,0)
        for c in range(1,s+1):
            for b in range(1,p+1):
                for a in range(1,j+1):
                    if (a,b,c) in res:
                        continue
                    k1 = sn1[(a,b)] + 1
                    k2 = sn2[(a,c)] + 1
                    k3 = sn3[(b,c)] + 1
                    if k1 > k  or k2 > k  or k3 > k :
                        continue
                    if max(k-k1,k-k2,k-k3) >= max(k-k1m,k-k2m,k-k3m) or (k1,k2,k3) <= (k1m,k2m,k3m):
                        cand = (a,b,c)
                        k1m,k2m,k3m = k1,k2,k3

        if cand == (0,0,0):
            break
        else:
            a,b,c = cand
            res.append(cand)
            sn1[(a,b)] += 1
            sn2[(a,c)] += 1
            sn3[(b,c)] += 1
    print "Case #" +  str(case_num) + ": " + str(len(res))
    for i in res:
        print " ".join(str(q) for q in i)
    case_num += 1