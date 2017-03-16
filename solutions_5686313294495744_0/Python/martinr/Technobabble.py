def solve(T):
    fakes = []
    for t1 in T:
        T.remove(t1)
        W1 = set([t[0] for t in T])
        W2 = set([t[1] for t in T])
        if t1[0] in W1 and t1[1] in W2:
            fakes.append(t1)
        else:
            T.insert(0, t1)
    return len(fakes)
        
    

#filespec = "e:/work/code_jam/Technobabble.txt"    
filespec = "d:/downloads/C-small-attempt0.in"
#filespec = "d:/downloads/A-large.in"
#filespec = "e:/work/code_jam/test.txt"    
f = open(filespec, 'r')
out = open("e:/work/code_jam/out.txt", 'w')

T = int(f.readline())
for nbr in range(1, T+1):
    
    N=int(f.readline())
    topics = []
    for _ in xrange(N):
        w1, w2 = f.readline().split()
        topics.append((w1, w2))
        
    topics.sort()
    sol = solve(topics)
    
    s = "Case #%d: %s\n" %(nbr, sol)
    print s,

    out.write(s)
    

f.close()
out.close()


