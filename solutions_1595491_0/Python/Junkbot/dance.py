T = int(raw_input())

for t in xrange(1,T+1):
    inputline = map(int,raw_input().strip().split())
    N = inputline[0]
    S = inputline[1]
    p = inputline[2]

    scores = sorted(inputline[3:])[::-1]
    done = 0
    surp = 0

    for i in xrange(N):
        best = scores[i]/3
        if scores[i]%3 > 0:
            best += 1
        
        if best >= p:
            done += 1
        elif (scores[i]%3 == 0 and scores[i]/3+1 <= 10 and scores[i]/3-1 >= 0) or (scores[i]%3 == 2 and scores[i]/3+2 <= 10 and scores[i]/3 >= 0):
            best += 1
            if best >= p:
                surp += 1

    done += min(surp, S)

    print "Case #%d: %d" % (t, done)

