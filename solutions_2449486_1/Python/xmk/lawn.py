f=open("input")
ff=open("output", "w")
readint=lambda :int(f.readline())
readintarray=lambda :map(int, f.readline().split())
T=readint()
for casex in range(1,T+1):
    N,M=readintarray()
    mat=[readintarray() for i in range(N)]
    #print N,M
    #print mat
    rmax=[max(mat[i]) for i in range(N)]
    #print "rmax",rmax
    cmax=[max(mat[i][j] for i in range(N)) for j in range(M)]
    #print "cmax",cmax
    ans=all(mat[i][j] in (rmax[i],cmax[j]) for i in range(N) for j in range(M))
    print >>ff, "Case #%d:"%casex, ["NO", "YES"][ans]
    
ff.close()
