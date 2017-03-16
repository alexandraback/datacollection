import sys
testcount = int(sys.stdin.readline())
for i in range(1,testcount+1):
    line = sys.stdin.readline().split(' ')
    for k in range(len(line)):
        line[k] = int(line[k])
    (n, s, p) = line[0:3]
    #print n,s,p
    t = line[3:]
    t.sort()
    t.reverse()
    #print t
    ans = 0
    for score in t:
        if score >= p+max(p-1,0)*2:
            ans += 1
        elif score >= p+max(p-2,0)*2 and s>0:
            s -= 1
            ans += 1
    print "Case #%d: %d" % (i, ans)
