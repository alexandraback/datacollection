import sys,math

def cases(P):
    for nowdigit in range(0,P[0]):
        if len(P) > 1:      
            for case in cases(P[1:len(P)]):
                ret = [nowdigit]
                ret.extend(case)
                yield ret
        else:
            yield [nowdigit]

if __name__ == "__main__":
    T = int(sys.stdin.readline())
    for t in range(0,T):
        D = int(sys.stdin.readline())
        string = sys.stdin.readline().rstrip()
        pin = string.split(' ')
        pin.sort()
        P = []
        for pi in pin:
            P.append(int(pi))

        mincase = 10
        for case in cases(P):
            maxnum = 0
            for i in range(0,len(P)):
                maxnum = max(maxnum,int(math.ceil(P[i]/(case[i]+1.0))))
            mincase = min(mincase,maxnum+sum(case))
        print "Case #%d: %d" % (t+1, mincase)
