from sys import stdin as IN
for _ in range(int(IN.readline())):
    print "Case #%s:" % (_+1),
    c, j = IN.readline().strip().split()
    answer = [c.replace("?", "0"), j.replace("?", "0")]
    best = 10**len(c)*10
    for i in range(10**len(c)):
        si = ("%%0%sd" % len(c)) % i
        match = True
        for _ in range(len(c)):
            if j[_] != "?" and j[_] != si[_]:
                match = False
                break
        if not match:
            continue
        for k in range(10**len(c)):
            sk = ("%%0%sd" % len(c)) % k
            match = True
            for _ in range(len(c)):
                if c[_] != "?" and c[_] != sk[_]:
                    match = False
                    break
            if not match:
                continue
            if abs(k - i) < best:
                best = abs(k-i)
                answer = [sk, si]
    print " ".join(answer)
