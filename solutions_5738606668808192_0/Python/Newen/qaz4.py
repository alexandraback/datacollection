import random
import  math
n = 16
j = 50

found = 0

print "Case #1:"
while found != j:
    cur = ((random.randint(0,(1 << (n-2))-1)) << 1) + 1 + (1 << (n-1))
    res = []
    for base in range(2,11):
        cand = int(bin(cur)[2:],base)
        #print  cand
        for q in range(2,int(math.sqrt(cand)+1)):
            if cand % q == 0:
                res.append(q)
                break
    if len(res) == 9:
        found += 1
        print bin(cur)[2:] + ' ' + ' '.join([str(x) for x in res])