infile = open('A-large.in','r')
outfile = open('A-large.out','w')
T = int(infile.readline())
for t in xrange(1,T+1):
    N = int(infile.readline())
    inherit = [[]] * N
    for n in xrange(N):
        inherit[n] = [int(tok)-1 for tok in infile.readline().split()][1:]
    answer = "No"
    for cla in xrange(N):
        seen = [False] * N
        bfs = [cla]
        seen[cla] = True
        while(bfs):
            x = bfs[0]
            bfs.remove(bfs[0])
            for inh in inherit[x]:
                if(seen[inh]):
                    answer = "Yes"
                    bfs = []
                    break
                else:
                    seen[inh] = True
                    bfs.append(inh)
            
    
    output = "Case #" + str(t) + ": " + answer + "\n"
    outfile.write(output)
infile.close()
outfile.close()
