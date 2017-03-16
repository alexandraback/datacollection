import os

def gf(v):
    ret = os.popen('gfactor %s | cut -d " " -f 2' % v).read().strip()
    return int(ret)

print "Case #1:"
bn = (1 << 32) - 1
cnt = 500
while (cnt > 0):
    ans = []
    x = bin(bn)[2:]
    flag = True
    for i in xrange(2, 11):
        y = int(x, i)
        p = gf(y)
        if p != y:
            ans += [p]
        else:
            flag = False
            break
    if flag:
        print x, " ".join(map(str, ans))
        cnt -= 1
    bn -= 2



    
