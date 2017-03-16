# google code jam 2012 round 1b

# safety in numbers



f = open("c:\\users\\James\\Downloads\\A-small-attempt1.in", "r")
#f = open("safety.in","r")
fout= open("safety.out", "w")

t = int(f.readline())

for t1 in xrange(t):
    # m chars already typed out of n total
    s = map(int, f.readline().split() )
    n = s[0]
    s = s[1:]
    x = sum(s)

    """
    worst case for contestant #i:
    lowest score (not me) gets all votes I don't

    If I get y, my score is score[i] + y*x
    Threshold score is  low + (1-y)*x
    My margin is   score +y*x - low - (1-y)*x >=0
    score - low + y*x - x + y*x >=0
    score - low -x >= -2yx
    (score - low - x)/(-2x) <= y

    but...
    If there are ties for the lowest score, then they all have
    to divide the remaining 1-y

    score +y*x >= low + (1-y)*x /count
    y*x + y*x/count >= low - score + x/count
    y >= (low-score + x/count) /x / (1+1/count)

    ugh.  nvm.
    Need to fill in all scores from lowest up.
    """

    answer = "Case #%d:" % (t1+1)
    score = sorted(s)

##    print score
##    print index

    # now start filling in scores from bottom
        
    i = 0
    y = x

    while i+1<n:
        delta = float(score[i+1]-score[i])
        if delta*(1+i) > y:
            print "stopping at %d of %d" %(i,n)
            break
        #print "i=%d, delta=%f" % (i, delta)
        score[i] += delta
        y -= delta*(i+1)
        i +=1

    target = score[i] + y*1.0/(i+1)

    total =0
    for i in range(n):
        delta = target - s[i]
        percent = delta*100.0/x
        percent = max(0, percent)
        total += percent
        answer += " %.5f" % percent
    answer += "\n"
        
    print answer,
    print total
        
    fout.write( answer )
fout.close()
        
