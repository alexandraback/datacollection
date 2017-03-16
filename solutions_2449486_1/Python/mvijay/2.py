import numpy

n = int(raw_input(""))

for i in range(0,n):
    m,n = map(int, raw_input("").split())
    mat = [[0]*n for j in range(0,m)]
    for j in range(0,m):
        l = map(int, raw_input("").split())
        for k in range(len(l)):
            mat[j][k]= l[k]

    mat = numpy.array(mat)
    rCut = mat.max(axis = 1)
    cCut = mat.max(axis = 0)
    poss = True
    for j in range(0,m):
        for k in range(0,n):
            if mat[j][k] != min(rCut[j], cCut[k]):
                poss = False
    if poss:
        print "Case #%d: YES"%(i+1)
    else:
        print "Case #%d: NO"%(i+1)        
                
    
