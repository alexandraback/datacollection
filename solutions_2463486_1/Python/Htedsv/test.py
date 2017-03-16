import math
"""
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
for x in range(10000000):
    if test(x) and test(x ** 2):
        li.append(x**2)
        li2.append(x)
        print x*x,','
        """

li = [ 0 , 1 , 4 , 9 , 121 , 484 , 10201 , 12321 , 14641 , 40804 , 44944 , 1002001 , 1234321 , 4008004 , 100020001 , 102030201 , 104060401 , 121242121 , 123454321 , 125686521 , 400080004 , 404090404 , 10000200001 , 10221412201 , 12102420121 , 12345654321 , 40000800004 , 1000002000001 , 1002003002001 , 1004006004001 , 1020304030201 , 1022325232201 , 1024348434201 , 1210024200121 , 1212225222121 , 1214428244121 , 1232346432321 , 1234567654321 , 4000008000004 , 4004009004004 , ]

import sys
cnt = 0
for x in open(sys.argv[1]).readlines():
    w = [int(i) for i in x.split(' ')]
    s = 0
    if len(w) == 2:
        cnt+= 1
        for y in range(len(li)):
            if li[y] >= w[0] and li[y] <= w[1]:
                s += 1
        print 'Case #%d: %d'%(cnt, s)

