def cmp(sn):
    return sn.replace("1","$").replace("0","1").replace("$","0")
def slides(b,m):
    l = []
    if m > 2**(b-2):
        return False, l
    else:
        bn = "{{:0{}b}}".format(b-2).format(2**(b-2)-m)[-b+2:]
        if b == 2: bn = ""
        l.append("0" + cmp(bn) + "1")
        for i in range(2,b+1):
            l.append("0"*i + "1"*(b-i))
        return True, l
            
            
t = int(raw_input())

for i in range(t):
    b, m = map(int, raw_input().split())
    res, l = slides(b, m)
    if not res:
        print "Case #{}: {}".format(i+1, "IMPOSSIBLE")
    else:
        #print b, m
        print "Case #{}: {}".format(i+1, "POSSIBLE")
        print "\n".join(l)
