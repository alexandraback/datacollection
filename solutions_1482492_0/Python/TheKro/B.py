import math

# It's a bloody DP for N > 2
def ans(a):
    time, pos, vel = 0., 0., 0.
    for n in range(1, N):
        gaptime = spots[n][0] - time
        if math.fabs(gaptime) > 1e-8:
            ovel = (spots[n][1] - spots[n-1][1])/(spots[n][0] - spots[n-1][0])
            fastest = vel+gaptime*a
            if fastest < ovel:
                #max accel all the way
                #print "Full throttle, still slower"
                pos += gaptime*vel+0.5*a*gaptime*gaptime
                time = spots[n][0]
                vel += gaptime * a
            else:
                #max accel until/if i catch, then track his speed
                distgap = pos - spots[n-1][1] #negative
                velgap = ovel - vel #positive
                intersect = (velgap+math.sqrt(velgap*velgap-2*a*distgap))/a
                if intersect < gaptime:
                    #print "Tailgating"
                    pos = spots[n][1]
                    time = spots[n][0]
                    vel = ovel
                else: # max accel, go faster but don't catch
                    #print "Full throttle, don't catch"
                    time = spots[n][0]
                    pos += gaptime*vel+0.5*a*gaptime*gaptime
                    vel += gaptime * a
            #print "Time, pos, vel:", time, pos, vel
    if pos < D:
        # If not at home, move last bit at max accel, update time
        gaptime = (-vel+math.sqrt(vel*vel-2*a*(pos-D)))/a
        time += gaptime
        pos += gaptime*vel+0.5*a*gaptime*gaptime
        vel += gaptime * a
        #print "Home stretch"
        #print "Time, pos, vel:", time, pos, vel
    return time
    
if __name__=="__main__":
    T = int(raw_input())
    for t in range(1, T+1):
        D, N, A = raw_input().split()
        D = float(D)
        N = int(N)
        A = int(A)
        spots = []
        for n in range(N):
            spots.append(map(float, raw_input().split())) #ti, xi pairs
            if spots[n][1] > D:
                if n == 0:
                    spots[n][1] = D
                else:
                    fulldist = spots[n][1] - spots[n-1][1]
                    fulltime = spots[n][0] - spots[n-1][0]
                    part = D - spots[n-1][1]
                    spots[n][0] = spots[n-1][0] + (part/fulldist)*fulltime
                    spots[n][1] = D
                    #print "New t,x", spots[N-1]
        print "Case #"+str(t)+":"
        accel = map(float, raw_input().split())
        for a in accel:
            print ans(a)
