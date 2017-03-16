import sys
import math

def quad(d,di,v,a):
    return ((-v + math.sqrt(v*v + 2*a*(d-di)))/a)

def solve(T,a,d):
    t,v,di = 0,0,0
    for i in range(1,len(T)):
        #print di,t,v,a
        dist = di + v*(T[i][0]-t) + 0.5*a*pow(T[i][0]-t,2)
        if(dist > d) and (T[i][1] > d):
            t_c = ((T[i][0]-T[i-1][0])/(T[i][1]-T[i-1][1]))*(d-T[i-1][1])
            #print "weird case"
            t += quad(d,di,v,a)
            if(t < t_c):
                t = t_c
            di = d
            break
        elif(dist > T[i][1]):
            u = math.sqrt(2*a*(T[i][1]-di))
            di = T[i][1]
            v = (T[i][1]-T[i-1][1])/(T[i][0]-T[i-1][0])
            if u > v:
                v = u
        else:
            di = dist
            v = v + a*(T[i][0]-t)
        t = T[i][0]
    if(di < d):
        #print di,t,v,a
        t += quad(d,di,v,a)
    return t

T = int(sys.stdin.readline())
for i in range(T):
    line = sys.stdin.readline().split()
    d = float(line[0])
    N,a = map(int,line[1:])
    t = []
    A = []
    for j in range(N):
        t.append(tuple(map(float,sys.stdin.readline().split())))
    A = map(float,sys.stdin.readline().split())
    print "Case #%d:"%(i+1)
    for j in range(len(A)):
        val = solve(t,A[j],d)
        print "%f"%val
