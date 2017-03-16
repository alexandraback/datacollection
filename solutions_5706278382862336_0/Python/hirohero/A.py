import math

f = open('A-small-attempt0.in','r').readlines()
fout = open('A-small-attempt0.out','w')

test = int(f[0].strip())


def GPM(a,b):
    while b > 0:
        c = a % b
        a = b
        b = c
    return a

pow2 = []
now = 1
for i in range(50):
    pow2.append(now)
    now = now * 2
    
for i in range(test):
    p, q = f[i + 1].strip().split('/')
    p, q = int(p), int(q)
    u = GPM(p, q)
    p = int(p/u)
    q = int(q/u)
    s = 'Case #' + str(i + 1) + ': '
    if not q in pow2:
        s = s + 'impossible'
    else:
        now = 0
        while pow2[now + 1] <= p:
            now += 1
        s = s + str(pow2.index(q) - now)

    print >> fout, s

fout.close()
