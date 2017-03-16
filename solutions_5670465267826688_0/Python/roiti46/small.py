sign_ref = {"11":1, "1i": 1, "1j": 1, "1k": 1,
            "i1":1, "ii":-1, "ij": 1, "ik":-1,
            "j1":1, "ji":-1, "jj":-1, "jk": 1,
            "k1":1, "ki": 1, "kj":-1, "kk":-1}

mul = {"11":"1", "1i":"i", "1j":"j", "1k":"k",
       "i1":"i", "ii":"1", "ij":"k", "ik":"j",
       "j1":"j", "ji":"k", "jj":"1", "jk":"i",
       "k1":"k", "ki":"j", "kj":"i", "kk":"1"}

T = int(raw_input())
for loop in xrange(T):
    L, X = map(int, raw_input().split())
    S = raw_input()
    S = S*X
    sign = 1

    make_i = make_j = False
    e = S[0]
    for i in xrange(1,L*X):
        if e == "i":
            make_i = True
            sp = i
            break
        sign *= sign_ref[e+S[i]]
        e = mul[e+S[i]]
    if not make_i:
        print "Case #%d: %s"%(loop+1, "NO")
        continue

    e = S[sp]
    for i in xrange(sp+1, L*X):
        if e == "j":
            make_j = True
            sp = i
            break
        sign *= sign_ref[e+S[i]]
        e = mul[e+S[i]]
    if not make_j:
        print "Case #%d: %s"%(loop+1, "NO")
        continue

    e = S[sp]
    for i in xrange(sp+1, L*X):
        sign *= sign_ref[e+S[i]]
        e = mul[e+S[i]]

    if sign == 1 and e == "k":
        print "Case #%d: %s"%(loop+1, "YES")
    else:
        print "Case #%d: %s"%(loop+1, "NO")        
