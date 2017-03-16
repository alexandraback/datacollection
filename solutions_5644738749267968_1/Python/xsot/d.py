for TC in range(1, int(raw_input())+1):
    n = int(raw_input())
    naomi = sorted(map(float, raw_input().split()))
    ken = sorted(map(float, raw_input().split()))
    
    a = naomi[:]
    b = ken[:]
    war_score = 0
    for i in range(n):
        if a[-1] < b[-1]:
            a = a[:-1]
            b = b[:-1]
        else:
            # if ken will lose, he plays his weakest block
            a = a[:-1]
            b = b[1:]
            war_score += 1
    
    a = naomi[:]
    b = ken[:]
    dec_score = 0
    for i in range(n):
        if a[0] < b[0]:
            # if ken will win, trick him to play strongest block
            a = a[1:]
            b = b[:-1]
        else:
            a = a[1:]
            b = b[1:]
            dec_score += 1
    
    print "Case #%d: %d %d" % (TC, dec_score, war_score)