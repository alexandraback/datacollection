import math

def f(P, D):
    if (D < 1) or (len(P) < 1):
        return 0
    hmax = max(P)
    hmin = min(P)
    if hmax < 4:
        return hmax
    y1 = hmax/2
    y2 = hmax - hmax/2
    Pnew = sorted(P)
    Pnew.pop()
    Pnew.append(y1)
    Pnew.append(y2)
    Dnew = D + 1
    min_stack = 1
    Pnew2 = [(z - min_stack) for z in P if (z - min_stack) > 0]
    Dnew2 = len(Pnew2)
    return min((1 + f(Pnew, Dnew)), (1 + f(Pnew2, Dnew2)))
   
def CASE(in1, in2):
    D = int(in1)
    P = map(int, in2.split())
    result = f(P,D)
    return str(result)

def RUN(IN, OUT):
    t = int(IN.readline().strip())
    for i in xrange(1, t + 1):
        in1 = IN.readline().strip() 
        in2 = IN.readline().strip()
        OUT.write("Case #%i: %s\n" % (i, CASE(in1, in2)))

if __name__ == "__main__":
    import sys
    RUN(sys.stdin, sys.stdout)
