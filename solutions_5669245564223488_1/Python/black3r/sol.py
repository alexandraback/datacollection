from collections import defaultdict
from math import factorial

N = int(input())
for I in range(1, N+1):
    n = int(input())
    ss = input().split()
    letters = 'abcdefghijklmnopqrstuvwxyz'
    begins = defaultdict(list)
    middles = defaultdict(list)
    ends = defaultdict(list)
    wtf = defaultdict(list)
    premature = False
    for s in ss:
        ends[s[0]].append(s)
        begins[s[-1]].append(s)
        same = True
        beginholds = True
        lastchar = s[0]
        wtfs = []
        for i in s:
            if i != lastchar:
                beginholds = False
                same = False
                wtfs.append(i)
            lastchar = i
        if same:
            middles[s[0]].append(s)
            begins[s[0]] = begins[s[0]][:-1]
            ends[s[0]] = ends[s[0]][:-1]
        w = set(wtfs[:-1])
        if (len(w) > 0) and s[0] == s[:-1]:
            result = 0
            premature = True
        for i in w:
            wtf[i].append(s)
    if premature:
        print("Case #%d: %s" % (I, str(0)))
        continue
    
    ## now we have begins, middles and ends
    ## rules are:
    ## IF in any letter we have a wtf and something other, they are unconnectable == no solution
    ## IF in any letter we have multiple endings they are unconnectable!
    ## IF in any letter we have multiple beginnings they are unconnectable!
    ## Now for each letter:
    ## sol *= factorial(len(middles))
#    print(begins)
#    print(middles)
#    print(ends)
#    print(wtf)
    sol = 1
    for i in letters:
        if len(begins[i]) > 1:
            sol *= 0
        if len(ends[i]) > 1:
            sol *= 0
        if len(wtf[i]) > 1:
            sol *= 0
        if len(wtf[i]) > 0 and (len(begins[i]) > 0 or len(ends[i]) > 0 or len(middles[i]) > 0):
            sol *= 0
        sol *= (factorial(len(middles[i])))
        sol %= 1000000007
    if sol == 0:
        print("Case #%d: %s" % (I, str(sol)))
        continue

    result = sol
    ## now we have the letter inner orderings. Now the bigger fun, connecting them to each other..
    ## if there is a tile, that is both beginning of one and ending of another letter.. they must be tied to each other.
    ## otherwise, they are independent.

    ## WE MUST CHECK FOR DEATHLOKs
    chains = [];
    used = set()

    deathlok = False
    for i in letters:
        chain = []
        t = i
        if len(begins[t]) == 1:
            chain.append(begins[t][0][0])        
        while len(begins[t]) == 1 and len(ends[t]) == 1:
            if t in chain:
                deathlok = True
                break
            chain.append(t)            
            used.add(t)
            t = ends[t][0][-1]            
        if len(begins[t]) == 1 or len(ends[t]) == 1 or len(middles[t]) > 0:
            if t in chain:
                deathlok = True
            chain.append(t)
        if deathlok:
            break
        chains.append(chain)
    if deathlok:
        result = 0
        print("Case #%d: %s" % (I, str(result)))
        continue    
    schains = [set(chain) for chain in chains]
    used = set()
    totalism = []
    for i in range(0, len(schains)):
        if i in used:
            continue
        used.add(i)
        s = schains[i]
        t = s
        for j in range(0, len(schains)):
            if j in used:
                continue
            k = schains[j]
            if not t.isdisjoint(k):
                if k.issuperset(t):
                    t = k
                used.add(j)
        if len(t) > 0:
            totalism.append(t)

    schains = totalism
    totalism = []
    used = set()
    for i in range(0, len(schains)):
        if i in used:
            continue
        used.add(i)
        s = schains[i]
        t = s
        for j in range(0, len(schains)):
            if j in used:
                continue
            k = schains[j]
            if not t.isdisjoint(k):
                if k.issuperset(t):
                    t = k
                used.add(j)
        if len(t) > 0:
            totalism.append(t)
#    print(schains)
#    print(totalism)
    result *= factorial(len(totalism))
    result %= 1000000007
    print("Case #%d: %s" % (I, str(result)))
