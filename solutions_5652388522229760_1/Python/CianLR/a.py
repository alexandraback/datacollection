T = int(raw_input())

for case in xrange(1, T+1):
    N = int(raw_input())

    if N == 0:
        print "Case #" + str(case) + ": INSOMNIA"
    else:
        i = 0
        seen = set()
        while len(seen) < 10:
            i += 1
            seen.update(str(N*i))
        
        print "Case #" + str(case) + ":", N*i
        
