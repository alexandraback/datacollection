def dobfs(grid, x, y):
    if grid[x][y]!='.':
        return grid
    currentmine = 0
    if x>0:
        if y>0:
            if grid[x-1][y-1]=="*":
                currentmine+=1
        if grid[x-1][y]=="*":
            currentmine+=1
        if y+1<len(grid[0]):
            if grid[x-1][y+1]=="*":
                currentmine+=1
    if y>0:
        if grid[x][y-1]=="*":
            currentmine+=1
        if y+1<len(grid[0]):
            if grid[x][y+1]=="*":
                currentmine+=1
    if x+1<len(grid):
        if grid[x+1][y]=="*":
            currentmine+=1
        if y>0:
            if grid[x+1][y-1]=="*":
                currentmine+=1
        if y+1<len(grid[0]):
            if grid[x+1][y+1]=="*":
                currentmine+=1
    grid[x][y]=currentmine
    if currentmine==0:
        if y+1<len(grid[0]):
            grid = dobfs(grid, x, y+1)
        if x+1<len(grid):
            grid = dobfs(grid, x+1, y)
            if y+1<len(grid[0]):
                grid = dobfs(grid, x+1, y+1)
    return grid

infile = open('csmall5.txt', 'r')
outfile = open('Cout.txt', 'w')

raw = infile.readline()
t = int(raw.rstrip())
for z in range(1, t+1):
    print(z)
    derp = "Case #"+str(z)+":"+"\n"
    outfile.write(derp)
    raw = infile.readline()
    raw = raw.split()
    raw = [int (i) for i in raw]
    r, c, m = raw[0], raw[1], raw[2]
    if r==1:
        outline = []
        outline.append('c')
        for i in range(1, c-m):
            outline.append('.')
        while len(outline)<c:
            outline.append("*")
        trueoutline = ""
        for each in outline:
            trueoutline+=each
        trueoutline+="\n"
        outfile.write(trueoutline)
    elif c==1:
        #print('c==1')
        outline=[]
        outline.append(['c'])
        for i in range(1, r-m):
            outline.append(['.'])
        while len(outline)<r:
            outline.append(["*"])
        for i in range(0, len(outline)):
            trueoutline = outline[i][0]+"\n"
            outfile.write(trueoutline)
    else:
        if r*c-m>1 and r*c-m<4:
            #print("Impossible")
            outline="Impossible"+'\n'
            outfile.write(outline)
        else:
            nonmines = r*c-m
            sqrlen = int(nonmines**0.5)
            grid = []
            for i in range(0, r):
                line=[]
                for j in range(0, c):
                    line.append('*')
                grid.append(line)
            if sqrlen<r and sqrlen<c:
                for i in range(0, sqrlen):
                    for j in range (0, sqrlen):
                        grid[i][j]='.'
                extra = nonmines-sqrlen*sqrlen
                if extra==1:
                    grid[sqrlen-1][sqrlen-1]='*'
                    extra=2
                for i in range(0, sqrlen):
                    if extra>0:
                        try:
                            grid[i][sqrlen]='.'
                            extra-=1
                        except:
                            pass
                if extra==1:
                    grid[sqrlen-1][sqrlen]="*"
                    extra+=1
                for j in range(0, sqrlen):
                    if extra>0:
                        try:
                            grid[sqrlen][j]='.'
                            extra-=1
                        except:
                            pass
            elif sqrlen>=r:
                sqrlen = nonmines//r
                for i in range(0, r):
                    for j in range (0, sqrlen):
                        grid[i][j]='.'
                extra = nonmines-sqrlen*r
                if extra==1:
                    grid[r-1][sqrlen-1]="*"
                    extra=2
                for j in range(0, r):
                    if extra>0:
                        try:
                            grid[j][sqrlen]='.'
                            extra-=1
                        except:
                            pass
            elif sqrlen>=c:
                sqrlen = nonmines//c
                for i in range(0, sqrlen):
                    for j in range (0, c):
                        grid[i][j]='.'
                extra = nonmines-sqrlen*c
                if extra==1:
                    grid[sqrlen-1][c-1]="*"
                    extra=2
                for i in range(0, c):
                    if extra>0:
                        try:
                            grid[sqrlen][i]='.'
                            extra-=1
                        except:
                            pass
            lines=[]
            grid[0][0]='c'
            for line in grid:
                outline=""
                for each in line:
                    outline+=str(each)
                outline+='\n'
                lines.append(outline)
            grid[0][0]='.'
            bfsgrid = dobfs(grid, 0, 0)
            dots = False
            print(bfsgrid)
            for i in range(0, len(bfsgrid)):
                for j in range(0, len(bfsgrid[0])):
                    if bfsgrid[i][j]=='.':
                        dots=True
                        break
            if dots==True:
                outline = "Impossible"+'\n'
                outfile.write(outline)
            else:
                for line in lines:
                    outfile.write(line)
outfile.close()
