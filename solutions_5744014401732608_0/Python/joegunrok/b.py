import math
from sys import stdin as IN
for _ in range(int(IN.readline())):
    print "Case #%s:" % (_+1),
    B, M = [int(_) for _ in IN.readline().strip().split()]
    most = 2**(B-2)
    plan = []
    for _ in range(B):
        plan.append([])
        for _ in range(B):
            plan[-1].append(0)
    if M > most:
        print "IMPOSSIBLE"
        continue
    n = 1
    i = 0
    plan[0][-1] = 1
    if M == 2 and B > 1:
        plan[0][-2] = 1
        plan[1][-1] = 1
    elif M > 1:
        while 2**i - 2**(i-1) <= M:
            i+=1
            for _i in range(i):
                plan[_i][-(i - _i)] = 1
            if n == M:
                break
            n*=2

        n = 2**(i-1)
        while n > M:
            diff = n-M
            if diff == 1:
                plan[0][-1] = 0
                n -= 1
                break
            _n = 1
            i = 0
            i = int(math.log(diff, 2))
            if i != math.log(diff, 2):
                i += 1
            plan[0][-(i+1)] = 0
            n -= 2**(i-1)
    print "POSSIBLE"
    print "\n".join(["".join(map(str,_)) for _ in plan])
