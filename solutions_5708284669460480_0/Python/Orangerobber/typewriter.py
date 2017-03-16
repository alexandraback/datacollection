import sys
from math import sqrt, floor

T = int(sys.stdin.readline())

for t in range(T):
    K, L, S = [int(x) for x in sys.stdin.readline().split()]
    alpha = sys.stdin.readline().strip()
    target = sys.stdin.readline().strip()

    if not (set(target).issubset(set(alpha))):
        print "Case #%d: 0"%(t+1)
        continue

    pw = 1
    a = len(alpha)
    for i in range(L):
        pw *= float(alpha.count(target[i])) / a

    exp = (S - L + 1) * pw

    a = L-1
    while not (target[:a] == target[-a:]):
        if(a==0):
            break
        a -= 1
    # a is overlap
    tot = 1
    S -= L
    tot += floor(float(S)/(L-a))

    print "Case #%d: %.07f"%(t+1,float(tot-exp))