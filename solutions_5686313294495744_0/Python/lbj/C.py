import itertools
t = int(raw_input())
for cn in range(t):
    s = int(raw_input())
    allv = []
    ps = [] # Proposals that have both words unique
    o1 = [] # Proposals that have one word unique
    w1 = set() # Set of first words
    w2 = set() # Set of second words
    for sn in range(s):
        p1, p2 = raw_input().split()
        ps.append((sn,p1,p2))
        allv.append((sn,p1,p2))
    adj1 = [[o for o in range(s) if e != o and ps[e][1] == ps[o][1]] for e in range(s)]
    adj2 = [[o for o in range(s) if e != o and ps[e][2] == ps[o][2]] for e in range(s)]
    # print("Fringe:", adj1, adj2)
    fakes = 0
    fringe = [e for e in range(s) if not adj1[e] or not adj2[e]]
    # Pick entry that introduces the most unique values
    # Clear out any fakes
    while ps or o1:
        # If we have something on either fringe, pick it
        # Otherwise, we have a cycle, pick arbitrarily
        if fringe:
            n = fringe.pop()
            n,a,b = allv[n]
            # print("Popping fringe:", n, a, b)
        elif ps:
            n,a,b = ps.pop()
            # print("Popping ps:", n,a,b)
        else:
            # print("Popping o1:", n,a,b)
            n,a,b = o1.pop()
        if a not in w1:
            w1.add(a)
        if b not in w2:
            w2.add(b)
        # print("Using topic:", n, a, b)
        nps = []
        no1 = []
        for nc,a,b in itertools.chain(ps, o1):
            if nc == n:
                continue # XXX
            if a in w1 and b in w2:
                fakes += 1
            elif a in w1:
                no1.append((nc,a,b))
            elif b in w2:
                no1.append((nc,a,b))
            else:
                # print "Neither", a, "nor", b, "in w1/w2"
                nps.append((nc,a,b))
        ps = nps
        o1 = no1
    print("Case #%d: %s" % (cn + 1, fakes))
