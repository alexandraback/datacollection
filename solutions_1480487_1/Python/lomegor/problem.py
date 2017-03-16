#!/usr/bin/python

import sys

cases = int(sys.stdin.readline())
for case in range(1,cases+1):
    points = map(int,sys.stdin.readline().rstrip().split(' '))
    N = points[0]
    points.remove(N)
    w = []
    tot = sum(points)
    n = len(points)
    extra = 0
    for p in points:
        x=(2*tot-p*n)/float(tot*n)
        if x<0:
            extra+=(x*100)
            x=0
        w.append(x*100)
    while extra:
        e2=0
        count =0
        for i in range(0,len(w)):
            if w[i]!=0:
                count+=1
        n = extra/float(count)
        for i in range(0,len(w)):
            if w[i]!=0:
                a = w[i]+n
                if a<0:
                    e2+=a
                    w[i]=0
                else:
                    w[i]=a
        extra = e2
    sys.stdout.write("Case #"+str(case)+":")
    for a in w:
        sys.stdout.write(" %.6f" % a)
    print
