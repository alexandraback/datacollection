import sys, math

f = sys.stdin
T = int(f.readline())
for tc in xrange(1,T+1):
    print 'Case #%d:' % tc
    l = f.readline().split()
    D = float(l[0])
    N,A = int(l[1]),int(l[2])
    Nl = []
    for i in range(N):
        Nl.append( tuple([float(val) for val in f.readline().split()]) )
    Al = [float(val) for val in f.readline().split()]
    if N == 1:
        for ai in Al:
            print math.sqrt(2 * D / ai)
    elif N == 2:
        v0 = (Nl[1][1] - Nl[0][1])/(Nl[1][0] - Nl[0][0])
        for ai in Al:
            t_oth = (D-Nl[0][1])/v0
            t_car = math.sqrt(2 * D / ai)
            print max([t_car, t_oth])
    else :
        u = 0.0
        totalt = 0.0
        dist_covered = 0.0
        for ai in Al:
            for i in xrange(1,N):
                vi = (Nl[i][1] - Nl[i-1][1])/(Nl[i][0] - Nl[i-1][0])
                d = min([ Nl[i][1], D] ) - dist_covered
                if d <= 0:
                    break
                if D < Nl[i][1] :
                    t_oth = (D-Nl[i-1][1])/vi
                else :
                    t_oth = Nl[i][0] - Nl[i-1][0]
                t_car = ( -u + math.sqrt(u**2 + (8*ai*d)) )/ (2*ai)
                dist_covered += d
                totalt += max([t_car, t_oth])
                if t_oth <= t_car :
                    u += ai*t_car
                else :
                    u = vi
            print totalt
            
            
