import time, string, numpy as np

t = time.time();
f = open('B-large.in','r')
fout = open('output.txt','w')
ncases = int(f.readline())
for i in range(ncases):
    # read K, N
    AB = f.readline().split() #remove the "\n"
    N = int(AB[0])
    M = int(AB[1])

    L = np.zeros((N,M))
    maxr = np.zeros(N)
    maxc = np.zeros(M)
    for r in range(N):
        AB = f.readline().split()  #remove the "\n"
        L[r,:] = np.array( [int(x) for x in AB] )
        maxr[r] = max(L[r,:])

    for c in range(M):
        maxc[c] = max(L[:,c])


    K = np.zeros((N,M))
    for r in range(N):
        for c in range(M):
            K[r,c] = min(maxc[c], maxr[r])

    #Compare original with refashioned
    d = np.max(K - L)
    if abs(d) < 1:
        c = 'YES'
    else:
        c = 'NO'



    casedesc = 'Case #' + str(i+1) + ': ' + str(c) + '\n'
    fout.write( casedesc )

fout.close()
f.close()
print "Time per case:", (time.time() - t) / ncases



