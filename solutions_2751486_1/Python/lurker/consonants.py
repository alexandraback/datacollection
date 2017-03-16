rl = raw_input

T = int(rl())

for case in xrange(T):
    text, N = rl().split()
    N = int(N)

    consecutive = [ 0 for i in xrange(len(text))]
    d = [0 for i in xrange(len(text))]

    run = 0
    vowel = set(['a','e','i','o','u'])
    for i in xrange(len(text)):
        if text[i] in vowel:
            consecutive[i] = 0
            run = 0
        else:
            run += 1
            consecutive[i] = run

    recent_starting = -1
    for i in xrange(len(text)):
        if consecutive[i] >= N:
            recent_starting = i - N + 2
        #print recent_starting
        if recent_starting >=0 :
            d[i] = d[i-1] + recent_starting
        else:
            d[i] = 0
    print "Case #%d: %d" %(case+1, d[-1])

