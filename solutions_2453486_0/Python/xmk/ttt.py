f=open("input")
ff=open("output", "w")
readint=lambda :int(f.readline())
enc={'X': -1, 'O':1, 'T': 1j, '.':0}
readarray=lambda :[enc[x] for x in f.readline().strip()]
T=readint()
def check(mat):
    for i in range(4):
        r=sum(mat[i])
        if abs(r)>3:
            return r
        r=sum(mat[j][i] for j in range(4))
        if abs(r)>3:
            return r
    r=sum(mat[j][j] for j in range(4))
    if abs(r)>3:
            return r
    r=sum(mat[3-j][j] for j in range(4))
    if abs(r)>3:
            return r
    return None
        
for casex in range(1,T+1):
    r=0
    mat=[readarray() for i in range(4)]
    f.readline()
    #print mat
    r=check(mat)
    result="Draw"
    if r:
        result = ["X won", "O won"][r.real>0]
    else:
        if any(mat[i][j]==0 for i in range(4) for j in range(4)):
            result="Game has not completed"
    print >>ff,"Case #%d:"%casex, result
    
ff.close()
