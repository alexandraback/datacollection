import sys

data = sys.stdin.readlines()
#n = int(data[0])
#print n
i = 1
for s in data[1:]:
    x = map(int, s.split())
    n, s, p = x[:3]
    cnt = 0
    cnt2 = 0
    #print n, s, p
    for k in x[3:]:
        if (k+2)/3 >= p:
            cnt += 1
        elif k >= 2 and (k+4)/3 >= p:
            cnt2 += 1
    tot = cnt + min(s, cnt2)
    print "Case #%d: %d" % (i, tot)
    i += 1
