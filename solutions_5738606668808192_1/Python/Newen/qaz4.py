import random
import  math
n = 32
j = 500

found = 0

print "Case #1:"
while found != j:
    cur = ((random.randint(0,(1 << (n-2))-1)) << 1) + 1 + (1 << (n-1))
    res = []
    for base in range(2,11):
        cand = int(bin(cur)[2:],base)
        q = 2
        flag = True
        while q <= 100000:
            if cand % q == 0:
                flag = False
                res.append(q)
                break
            q += 1
        if flag:
            break
    if len(res) == 9:
        found += 1
        print bin(cur)[2:] + ' ' + ' '.join([str(x) for x in res])