

def findCandidates(S1, S2, db):

    l = len(S1)

    O1 = ""
    O2 = ""

    def maxS(inp, S, j):
        out = inp
        for i in range(j, l):
            c = S[i]
            if c == "?":
                out += "9"
            else:
                out += c
        return out

    def minS(inp, S, j):
        out = inp
        for i in range(j, l):
            c = S[i]
            if c == "?":
                out += "0"
            else:
                out += c
        return out

    def add(T1, T2):
        #print T1, T2
        db.append((T1,T2))


    for i in range(0, l):
        c1 = S1[i]
        c2 = S2[i]
        abort = False
        if ( c1 == "?" and c2 == "?" ):
            if ( True ):
                c1 = str(0)
                c2 = str(1)
                # maxa c1, minska c2
                T1 = maxS(O1+c1, S1, i+1)
                T2 = minS(O2+c2, S2, i+1)
                add(T1,T2)
            if ( True ):
                c1 = str(1)
                c2 = str(0)
                # minska c1, maxa c2
                T1 = minS(O1+c1, S1, i+1)
                T2 = maxS(O2+c2, S2, i+1)
                add(T1,T2)
            O1 += str(0)
            O2 += str(0)
        elif ( c1 == "?" ):
            if ( int(c2) > 0 ):
                c1 = str( int(c2)-1 )
                # maxa c1, minska c2
                T1 = maxS(O1+c1, S1, i+1)
                T2 = minS(O2+c2, S2, i+1)
                add(T1,T2)
            if ( int(c2) < 9 ):
                c1 = str( int(c2)+1 )
                # minska c1, maxa c2
                T1 = minS(O1+c1, S1, i+1)
                T2 = maxS(O2+c2, S2, i+1)
                add(T1,T2)
            O1 += c2
            O2 += c2
        elif ( c2 == "?" ):
            if ( int(c1) > 0 ):
                c2 = str( int(c1)-1 )
                # maxa c2, minska c1
                T1 = minS(O1+c1, S1, i+1)
                T2 = maxS(O2+c2, S2, i+1)
                add(T1,T2)
            if ( int(c1) < 9 ):
                c2 = str( int(c1)+1 )
                # minska c2, maxa c1
                T1 = maxS(O1+c1, S1, i+1)
                T2 = minS(O2+c2, S2, i+1)
                add(T1,T2)
            O1 += c1
            O2 += c1
        elif ( c1 != c2 ):
            if ( int(c1) < int(c2) ):
                # minska c2, maxa c1
                T1 = maxS(O1+c1, S1, i+1)
                T2 = minS(O2+c2, S2, i+1)
                add(T1,T2)
            else:
                # maxa c2, minska c1
                T1 = minS(O1+c1, S1, i+1)
                T2 = maxS(O2+c2, S2, i+1)
                add(T1,T2)
            abort = True
            break
        else:
            O1 += c1
            O2 += c2
    if not abort:
        add(O1, O2)



def findBest(db):
    best = 99999999999999999999999999999
    out = []
    for i in range(0, len(db)):
        pair = db[i]
        p1 = pair[0]
        p2 = pair[1]
        diff = abs(int(p1) - int(p2))
        if ( diff == best ):
            out.append(pair)
        elif ( diff < best ):
            out = []
            out.append(pair)
            best = diff
    return out



def solve(S1, S2):

    print S1, S2
        
    db = []

    findCandidates(S1, S2, db)

    best = findBest(db)
    
    thebest = sorted(best)[0]
    
    return thebest


f = open("match.large.in", "r")

T = int(f.readline())
S1 = []
S2 = []

for i in range(0, T):
    l = f.readline().strip()
    S1.append( l.split(" ")[0] )
    S2.append( l.split(" ")[1] )

f.close()

f = open("match.out", "w")

for m in range(0, T):
    best = solve(S1[m], S2[m])
    f.write("Case #" + str(m + 1) + ": " + best[0] + " " + best[1] + "\n")
        
f.close()

print "done"
