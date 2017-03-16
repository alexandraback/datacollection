def func(r,t):

    count = 0;
    temp = 0;
    while (temp<=t):
        temp += (r+1)**2 - r**2
        r +=2;
        count +=1;

    return count-1


# main
T = int(raw_input())

for i in xrange(0,T):
    r, t = raw_input().split(" ")
    r, t = int(r), int(t)
    print "Case #%d:" % (i+1), func(r,t)
