import math
def divide(x):
    for i in range(2, int(math.sqrt(x+1))):
        if x % i == 0: return str(i)+'*'+divide(x/i)
    return str(x)
def iter(x):
    if x < 10: return x
    else:
        return ((x%10)* (10**int(math.log(x, 10)))) + iter(x/10)

def test(x):
    if x == iter(x): return True
    return False

li = []
li2 = []
for x in range(10000):
    if test(x ** 2):
        li.append(x**2)
        li2.append(x)


import sys
cnt = 0
for x in open(sys.argv[1]).readlines():
    w = [int(i) for i in x.split(' ')]
    s = 0
    if len(w) == 2:
        cnt+= 1
        for y in range(len(li)):
            if li[y] >= w[0] and li[y] <= w[1] and test(li2[y]):
                s += 1
        print 'Case #%d: %d'%(cnt, s)

