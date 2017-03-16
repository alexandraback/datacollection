#for every position in the lawn, check to see if you can go to the edge without increasing in any direction
fin = open('lawn.in')
fout = open('lawn.out','w')
cases = int(fin.readline())
cnt=0
def pp(s):#print end case
    print 'Case #%d: ' % (cnt) +s
    fout.write('Case #%d: ' % (cnt) +s+'\n')
    
for case in xrange(cases):
    cnt+=1
    N, M = map(int, fin.readline().split(' '))
    #print N, M
    grid = []
    grid.append([0 for x in xrange(M+2)])
    for line in xrange(N):
        grid.append([0]+map(int, fin.readline().split(' '))+[0])
    grid.append([0 for x in xrange(M+2)])
    #print grid
    #print grid
    grid2 = zip(*grid)
    #print grid2
    done = False
    """
    for x in grid:
        print x
    print
    for x in grid2:
        print x
    x = 1
    y = 2
    print grid[x][y+1:]
    print grid[x][:y]
    print grid2[y][x+1:]
    print grid2[y][:x]
    print grid[6][1]
    """
    #val = 1
    #print (val<max(grid[x][y+1:]) or val<max(grid[x][:y])) and (val<max(grid2[y][x+1:]) or val<max(grid2[y][:x]))
    for y in xrange(1,M+1):
        for x in xrange(1,N+1):
            val = grid[x][y]
            #if val==1:
            #    print val, x,y,M,N
            if (val<max(grid[x][y+1:]) or val<max(grid[x][:y])) and (val<max(grid2[y][x+1:]) or val<max(grid2[y][:x])):
                done = True
                pp("NO")
                break
        else:
            continue
        break

    if not done:
        pp("YES")
fout.close()