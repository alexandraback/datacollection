import sys,math

if __name__ == "__main__":
    T = int(sys.stdin.readline())
    for t in range(0,T):
        D = int(sys.stdin.readline())
        string = sys.stdin.readline().rstrip()
        pin = string.split(' ')
        P = []
        for pi in pin:
            P.append(int(pi))
        P.sort()

        mindays = 1000*1000*100
        for thr in range(1,1000+1):
            special = 0
            for p in P:
                special += int(math.ceil(p/(thr+0.0))) - 1
            days = special + thr
            if mindays > days:
                mindays = days
        print "Case #%d: %d" % (t+1, mindays)
