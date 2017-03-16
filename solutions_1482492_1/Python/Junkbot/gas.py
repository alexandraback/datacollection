T = int(raw_input())

def tim(d, u, a):
    start = 0.0
    end = 10000000.0

    while end-start > 1e-9:
        mid = (start+end)/2

        s = u*mid + 0.5*a*mid*mid
        if s >= d:
            end = mid
        else:
            start = mid

    return start

for t in xrange(1,T+1):
    print "Case #%d:" % t
    line = raw_input().split()
    D = float(line[0])
    N = int(line[1])
    A = int(line[2])

#    print D,N,A

    pos = []
    for i in xrange(N):
        pos.append(map(float, raw_input().split()))

    ac = map(float,raw_input().split())
    for a in ac:
        cur = 0.0
        time = 0.0
        v = 0.0

        lastTime = pos[0][0]
        lastPos = pos[0][1]

        if lastPos < D:
            for i in xrange(1,N):
                dt = pos[i][0] - lastTime
                ds = pos[i][1] - lastPos
                if pos[i][1] > D:
                    pos[i][0] = pos[i-1][0] + (D - lastPos)/(ds/dt)
                    pos[i][1] = D
                dt = pos[i][0] - lastTime
                ds = pos[i][1] - lastPos

                if ds == 0 or pos[i][1] > D:
                    break

#                print "examining (%lf->%lf),(%lf->%.10lf) cur = %lf, time = %lf, v = %lf" % (lastPos,pos[i][1],lastTime,pos[i][0],cur,time,v)

                x = cur + v*dt + 0.5*a*dt*dt
                if x <= pos[i][1]:
#                print "route 1, dt=%lf" % dt
                    cur = x
                    v += a*dt
                else:
                    cur = pos[i][1]
                    k = tim(ds, v, a)
                    v += a*k

                time += dt

                lastTime = pos[i][0]
                lastPos = pos[i][1]

#        print "at time %lf, cur = %lf, v = %lf" % (time, cur,v)
        if cur < D:
            time += tim(D - cur, v, a)
        print "%.8lf" % time

