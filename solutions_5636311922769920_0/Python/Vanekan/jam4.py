t = input()

for tc in range(1, t+1):
    k,c,s = raw_input().split()
    k = int(k)
    c = int(c)
    s = int(s)

    print "Case #"+str(tc)+":",
    for i in range(1, s+1):
        print i,
    print ""