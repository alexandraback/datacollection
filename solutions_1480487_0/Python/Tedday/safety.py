infile = open('A-small-attempt0.in','r')
outfile = open('A-small.out','w')
T = int(infile.readline())
for t in xrange(1,T+1):
    contest = [int(x) for x in infile.readline().split()][1:]
    outstr = ""
    Q = contest[0:]
    Q.sort()
    
    x = sum(contest)
    X = float(x)
    out = []
    for score in contest:
        L = Q + []
        #z = L.index(score) + L.count(score)-1
        L.remove(score)
        comp = 0
        s = 0
        #comp = z * score
        #s = sum(Q[:z])
        minimum = 1.0
        for i in xrange(len(L)):
            comp += score
            s += L[i]
            minimum = min(float((x-comp+s)/X)/(i+2),minimum)
        out.append(100.0 * max(minimum,0.0))
                
       
    for o in out:
        outstr += (' ' + str(o)) 
    output = "Case #" + str(t) + ":" + outstr + "\n"
    outfile.write(output)
infile.close()
outfile.close()
