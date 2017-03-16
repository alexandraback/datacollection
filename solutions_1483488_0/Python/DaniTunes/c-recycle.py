import sys

data = sys.stdin.readlines()
#n = int(data[0])
#print n
i = 1
for s in data[1:]:
    a, b = map(int, s.split())
    #print a, b
    k = len(str(a))
    cnt = 0
    for n in range(a, b+1):
        a = []
        for j in range(1, k):
            s = str(n)
            m = int(s[j:] + s[:j])
            #print n, m
            if n < m <= b and not m in a:
                cnt += 1
                #print n, m
                a.append(m)
    print "Case #%d: %d" % (i, cnt)
    i += 1
