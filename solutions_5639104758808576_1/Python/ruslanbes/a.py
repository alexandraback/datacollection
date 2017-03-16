def output(t, res):
    casestr = "Case #" + str(t+1) +": "
    status = str(res) if res != None else "impossible"
    outputLine = casestr+status
    print outputLine


def main():
    T = int( raw_input() )

    for t in xrange(T):    
        Smax, S = raw_input().split()
        Smax = int(Smax)
        S = [ int(s) for s in S ]
        needed = 0
        total = 0
        for i in xrange( Smax+1 ):
            if total < i:
                neededi = i - total
                needed += neededi
                total += neededi
            total += S[i]   
        output(t, needed)

if __name__ == "__main__":
   main()