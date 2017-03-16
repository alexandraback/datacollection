
def CalMax(a, b):
    assert len(a) == len(b)
    ra = []
    rb = []
    mx = 0
    for aa, bb in zip(a, b):
        aa = '9' if aa == '?' else aa
        bb = '0' if bb == '?' else bb
        mx = mx*10 + int(aa)-int(bb)
        ra += [aa]
        rb += [bb]

    return mx, "".join(ra), "".join(rb)

def CalMin(a, b, ha, hb):
    assert ha != hb
    ha = int(ha)
    hb = int(hb)
    if ha > hb:
        vv, bb, aa = CalMax(b, a)
        return (ha-hb)*(10**len(a))-vv, str(ha)+aa, str(hb)+bb
    else:
        vv, aa, bb = CalMax(a, b)
        return (hb-ha)*(10**len(a))-vv, str(ha)+aa, str(hb)+bb

ansmn = 10**19
ansa = ""
ansb = ""
n = 0
cur = ""

def cmp(tmn, ta, tb):
    global ansmn, ansa, ansb, n, cur
    assert tmn >= 0
    ta = cur+ta
    tb = cur+tb
    if tmn < ansmn:
        ansmn, ansa, ansb = tmn, ta, tb
    elif tmn == ansmn:
        if int(ta) < int(ansa):
            ansmn, ansa, ansb = tmn, ta, tb
        elif int(ta) == int(ansa):
            if int(tb) < int(ansb):
                ansmn, ansa, ansb = tmn, ta, tb
    
for case in range(1, int(raw_input())+1):
    print "Case #%d:"%case,
    a, b = raw_input().split()
    assert len(a) == len(b)
    n = len(a)
    ansa = ansb = "0"*n
    ansmn = 10**19
    cur = ""
    
    for i, (x, y) in enumerate(zip(a, b)):
        if x == '?' and y == '?':
            mn, ra, rb = CalMin(a[i+1:], b[i+1:], '1', '0')
            cmp(mn, ra, rb)
            mn, ra, rb = CalMin(a[i+1:], b[i+1:], '0', '1')
            cmp(mn, ra, rb)
            cur += '0'
        elif (x == '?') != (y == '?'):
            if x != '?':
                if x != '0':
                    mn, ra, rb = CalMin(a[i+1:], b[i+1:], x, str(int(x)-1))
                    cmp(mn, ra, rb)
                if x != '9':
                    mn, ra, rb = CalMin(a[i+1:], b[i+1:], x, str(int(x)+1))
                    cmp(mn, ra, rb)
                cur += x
            else:
                if y != '0':
                    mn, ra, rb = CalMin(a[i+1:], b[i+1:], str(int(y)-1), y)
                    cmp(mn, ra, rb)
                if y != '9':
                    mn, ra, rb = CalMin(a[i+1:], b[i+1:], str(int(y)+1), y)
                    cmp(mn, ra, rb)
                cur += y
        elif x != y:
            mn, ra, rb = CalMin(a[i+1:], b[i+1:], a[i], b[i])
            cmp(mn, ra, rb)
            break
        else:
            cur += x
    else:
        cmp(0, "", "")
    print "%s %s"%(ansa, ansb)


