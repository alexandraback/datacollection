def solve(file):
    import numpy
    
    
    f = open(file,'r')
    lines = f.readlines()
    nCases = int(lines[0])
    outf = open("output.txt",'w')
    i = 1 # line number
    n = 1 # case number
    while nCases > 0:
        print("case: " + str(n))
        line = lines[i].replace('\n', "").split(" ")
        H = int(line[0]) #R
        W = int(line[1]) #C
        M = int(line[2])

        outf.write("Case #" + str(n) +":\n" + single(W,H,M))

        i += 1
        nCases -= 1
        n+=1

    f.close()
    outf.close()


def single(W,H,M):
    import numpy

    flipped = False
    if H>W:
        print("flipped=true")
        flipped = True
        tmp = W
        W=H
        H=tmp
    
    #firstly ensure not bigger than area
    if (M>W*H or M < 0):
        return "Impossible\n"

    # setup
    F = H*W-M #non-bombs 'frees'
    grid =numpy.zeros( (W,H), dtype=int) #0:bomb, 1:free, 2:click
    
    if (F==0):
        print("ERROR F==0")
        return "Impossible\n"

        
    # if either dimension is 1: (easy)
    if (H==1):
        grid[0][0]=2
        for x in range(1,F):
            grid[x][0]=1
        return gridToString(grid,flipped)
    if (H==2):
        if F==1:
            grid[0][0]=2
            return gridToString(grid,flipped)
        elif F%2==1 or F==2:
            return "Impossible\n"
        else:
            for x in range(0,int(F/2)):
                grid[x][0]=1
                grid[x][1]=1
            grid[0][0]=2
            return gridToString(grid,flipped)
            
        
    # if either is 2: (easy)

    # if Free<9 (if both dims are 3 will work with zero below this)
    # here we know it is at least 3x3 total dimension
    # how can we arrange <9 frees in a 3x3 (or diffieren, but doesnt matter) grid

    if F==8:
        for x in range(0,3):
            for y in range(0,3):
                grid[x][y] = 1
        grid[2][2] = 0
        grid[0][0] = 2
        return gridToString(grid,flipped)
    elif F==7:
        return "Impossible\n"
    elif F==6:
        for x in range(0,3):
            for y in range(0,2):
                grid[x][y] = 1
        grid[0][0] = 2
        return gridToString(grid,flipped)
    elif F==5:
        return "Impossible\n"
    elif F==4:
        grid[0][0] = 2
        grid[1][0] = 1
        grid[0][1] = 1
        grid[1][1] = 1
        return gridToString(grid,flipped)
    elif F==3:
        return "Impossible\n"
    elif F==2:
        return "Impossible\n"
    elif F==1:
        grid[0][0] = 2
        return gridToString(grid,flipped)    


    # following works if Free>=9 AND W>=3 AND H>=3

    # we have established that the free square is (can be) at least 3x3

    #extend in any direction until any more would be over
    w=3
    h=3
    
    #fill init
    for x in range(0,3):
        for y in range(0,3):
            grid[x][y] = 1
    
    #increase width
    while w<W and w*h<F:       
        w+=1
        for y in range(0,h):
            if h*(w-1)+y+1 <= F:
                grid[w-1][y] = 1
            

    # if not yet completed, go down
    while h<H and w*h<F:            
        h+=1
        for x in range(0,w):
            if w*(h-1)+x+1 <= F:
                grid[x][h-1] = 1
    print(gridToString(grid,flipped))
    print("w: ", w, "h: ", h)
                
    if grid[w-1][1] == 0: # singleton
        grid[w-1][1] = 1
        assert(grid[w-2][h-1] == 1)
        grid[w-2][h-1] = 0 

    if grid[1][h-1] == 0: # singleton
        grid[1][h-1] = 1
        assert(grid[w-1][h-2] == 1)
        grid[w-1][h-2] = 0

    grid[0][0] = 2

    print(gridToString(grid,flipped))
    print("w: ", w, "h: ", h)
    
    return gridToString(grid,flipped)


def gridToString(grid,flipped):
    result = ""
    if (flipped == False):
        for y in range(0,grid.shape[1]):
            for x in range(0,grid.shape[0]):
                if grid[x][y] == 0:
                    result += '*'
                elif grid[x][y] == 1:
                    result += '.'
                elif grid[x][y] == 2:
                    result += 'c'
            result += "\n";
    else:
        print ("showing flipped")
        for x in range(0,grid.shape[0]):
            for y in range(0,grid.shape[1]):
                if grid[x][y] == 0:
                    result += '*'
                elif grid[x][y] == 1:
                    result += '.'
                elif grid[x][y] == 2:
                    result += 'c'
            result += "\n";
    return result

