def solve(A, B):
    n = A
    t = 0
    while n <= B:
        
        CACHE = set([])
        
        ns = str(n)
        for k in xrange(1, len(ns)):
            ns = ns[-1] + ns[:-1]
            if ns[0] == "0": continue
            m = int(ns)
            if m <= n or m > B: continue
            if m in CACHE: continue
            CACHE.add(m);
            t += 1
        
        n += 1
    return t

fin = open("c:/cj/C-large.in", 'r')
fout = open("c:/cj/c.OUT", 'w')

T = int(fin.readline().strip())

for case_nbr in xrange(1, T + 1):
    buff = fin.readline().strip().split();
    A = int(buff[0])
    B = int(buff[1])
    print "case#", case_nbr
    fout.write("Case #" + str(case_nbr) + ": " + str(solve(A, B)) + "\n")

fin.close()
fout.close()

print "done"
    

