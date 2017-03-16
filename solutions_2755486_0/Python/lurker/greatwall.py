import bisect

rl = raw_input

T = int(rl())

def process(tribes):
    # build schedule
    success = 0
    attacks = []
    idx_base = 2000
    castles = []
    for tribe in tribes:
        d, n, w, e, s, deltaD, deltaP, deltaS = tribe
        for i in xrange(n):
            attacks.append((d, w, e, s))
            d += deltaD
            w += deltaP
            e += deltaP
            s += deltaS
    at_dict = {}
    for d, w, e, s in sorted(attacks):
        if at_dict.has_key(d):
            at_dict[d].append((w,e,s))
        else:
            at_dict[d] = [(w,e,s)]

    for d in at_dict:
        # check success
        for w, e, s in at_dict[d]:
            #print d, w, e, s, castles, success
            failed = True
            for pos in xrange(w, e):
                cs = [cs for cw,ce,cs in castles if cw <= pos < ce]
                #print pos, "cs:", cs, s
                if not cs or cs[0] < s:
                    failed = False
                    break
            if not failed:
                success += 1

        for w, e, s in at_dict[d]:
            castles.append((w, e, s))

        castles = sorted(castles, reverse=True, key=lambda x:x[2])
    return success



for case in xrange(T):
    result = 0
    N = int(rl())
    tribes = []
    for tribe in xrange(N):
        d, n, w, e, s, deltaD, deltaP, deltaS = map(int, rl().split())
        tribes.append((d,n,w,e,s,deltaD,deltaP,deltaS))
    print "Case #%d: %d" %(case+1, process(tribes))