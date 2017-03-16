from collections import Counter

for case in range(input()):
    print "Case #"+str(case+1)+":",
    D = int(raw_input())
    P = sorted(map(int,raw_input().split()))
    P.sort()
    #print P
    min_time = 1001
    for eat_time in xrange(1, max(P) + 1):
        min_time = min(min_time, eat_time + sum((p-1)/eat_time for p in P))
    print min_time
