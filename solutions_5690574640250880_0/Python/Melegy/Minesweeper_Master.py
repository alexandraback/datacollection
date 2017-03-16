from copy import deepcopy as copy
ne=[(0,1),(1,0),(-1,0),(0,-1),(1,1),(-1,-1),(1,-1),(-1,1)]
def solve (r,c,m):
    grid=[]
    q=[]
    bombs=r*c
    for i in range(r):
        grid.append(["*" for i in range(c)])
    for i in range(r):
        for j in range(c):
            g=copy(grid)
            g[i][j]="c"
            bombs=r*c-1
            if bombs==m:
                    ret=""
                    for row in g:
                        ret+="\n"
                        ret+=''.join(row)
                    return ret
            for cell in ne:
                if -1<cell[0]+i<r and -1<cell[1]+j<c and g[i+cell[0]][j+cell[1]]!=".":
                    g[i+cell[0]][j+cell[1]]="."
                    bombs-=1
            if bombs==m:
                    ret=""
                    tmp_count=0
                    for row in g:
                        for col in row:
                            if col=="*":
                                tmp_count+=1
                    for row in g:
                        ret+="\n"
                        ret+=''.join(row)
                    return ret
            for cell in ne:
                if -1<cell[0]+i<r and -1<cell[1]+j<c :
                    q.append(((i+cell[0],j+cell[1]),g,bombs))
            
    while (len(q)>0):
        node=q.pop()
        p=node[0]
        g=copy(node[1])
        bombs=node[2]
        if bombs<m:
            continue
        temp=[]
        for cell in ne:
                if -1<cell[0]+p[0]<r and -1<cell[1]+p[1]<c and g[p[0]+cell[0]][p[1]+cell[1]]!="." and g[p[0]+cell[0]][p[1]+cell[1]]!="c":
                    g[p[0]+cell[0]][p[1]+cell[1]]="."
                    bombs-=1
                    temp.append((p[0]+cell[0],p[1]+cell[1]))
        for point in temp:
                    q.append((point,g,bombs))
        if bombs==m:
                    ret=""
                    tmp_count=0
                    for row in g:
                        for col in row:
                            if col=="*":
                                tmp_count+=1
                    for row in g:
                        ret+="\n"
                        ret+=''.join(row)
                    return ret
    print str(case)+","
    return "\nImpossible"
                
fin=open('../in','r') ; fout=open('../out','w')
cases=int(fin.readline().strip())
for case in range(1,cases+1):
    line=[int(x) for x in fin.readline().strip().split(' ')]
    r=line[0] ; c=line[1] ; m=line[2]
    fout.write("Case #"+str(case)+":"+str(solve(r,c,m))+"\n")