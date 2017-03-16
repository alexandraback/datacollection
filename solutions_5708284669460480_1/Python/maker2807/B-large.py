def lps(s):
    L = [s[i:] for i in range(1,len(s))]
    L.append("")
    #print L
    L = filter(lambda x: s.startswith(x), L)
    #print L
    return max(map(len,L))

def probOfTarget(tgt,kbd):
    fq = {}
    for c in kbd:
        if c not in fq:
            fq[c] = 0.0
        fq[c] += 1

    ret = 1.0
    for c in tgt:
        ret *= fq[c]/len(kbd)
    return ret

#print probOfTarget("Q","QSMQQQQ")

T = input()
for t in range(T):
    s = raw_input()
    (K,L,S) = map(int,s.split())
    keyboard = raw_input()
    target = raw_input()

    res = 0.0
    if (set(target) <= set(keyboard)) and len(target)<=S:
        maxc = 0
        x = lps(target)
        xx = S
        maxc += 1
        xx-=len(target)
        maxc += xx/(len(target)-x)

        prob = probOfTarget(target,keyboard)
        res = (S - len(target) + 1)*prob


        res = maxc-res

    print "Case #%d:"%(t+1,), res
    
