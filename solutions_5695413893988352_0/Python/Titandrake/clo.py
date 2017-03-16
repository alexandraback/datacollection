import time
ti = time.time()
from itertools import product

def ok(n1, n2, s1, s2):
    q1 = str(n1)
    q2 = str(n2)
    q1 = '0' * (len(s1) - len(q1)) + q1
    q2 = '0' * (len(s2) - len(q2)) + q2
    for i in range(len(s1)):
        if s1[i] != '?' and s1[i] != q1[i]:
            return False, 1, 2
    for i in range(len(s2)):
        if s2[i] != '?' and s2[i] != q2[i]:
            return False, 1, 2
    return True, q1, q2


t = int(raw_input())
for i in range(1, t+1):
    s1, s2 = raw_input().strip().split()
    best = 100000000
    bn1 = -1;
    bn2 = -1;
    for n1 in range(10 ** len(s1)):
        for n2 in range(10 ** len(s2)):
            if abs(n1 - n2) >= best:
                continue
            o, w, e = ok(n1,n2,s1,s2)
            if o:
                if abs(n1 - n2) < best:
                    best = abs(n1 - n2)
                    bn1 = w
                    bn2 = e
    print("Case #%d: %s %s" % (i, bn1, bn2))
