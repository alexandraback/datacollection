inputf = open("C-small-attempt0.in")


def solve(r, c, m):
    # assume r <= c
    b = r*c - m
    if (r==1):
        return [['.']*b + ['*']*m]
    if b==1:
        row1 = ['.'] + ['*']*(c-1)
        row2 = ['*']*c
        return [row1] + [row2]*(r-1)        
    if (r==2):
        if m%2 == 1 or b==2: return None
        return [['.']*(b//2) + ['*']*(m//2)]*2
    #c >= r >= 3
    if b in {2, 3, 5, 7}: return None
    for w in range(2, c+1):
        if b%w==1: continue
        if b%w==0:
            if b//w>r: continue
            row1 = ['.']*w + ['*']*(c-w)
            row2 = ['*']*c
            return [row1]*(b//w) + [row2]*(r-b//w)
        if b//w+1>r: continue
        row1 = ['.']*w + ['*']*(c-w)
        row2 = ['.']*(b%w) + ['*']*(c-(b%w))
        row3 = ['*']*c
        return [row1]*(b//w) + [row2] + [row3]*(r-b//w-1)
    # ghetto case
    if r==3:
        row1 = ['.']*(c-1)+['*']
        row2 = ['.']*3 + ['*']*(c-3)
        return [row1]*(r-1) + [row2]
    else:
        row0 = ['.']*c
        row1 = ['.']*(c-1)+['*']
        row2 = ['.']*2 + ['*']*(c-2)
        return [row0]*(r-2) + [row1] + [row2]

def do_case(r, c, m):
    if (r <= c):
        grid = solve(r, c, m)
        if grid != None:
            grid[0] = grid[0][:]
            grid[0][0] = 'c'
    else:
        grid = solve(c, r, m)
        if grid != None:
            grid[0] = grid[0][:]
            grid[0][0] = 'c'
            grid = zip(*grid)

    if grid is None:
        print("Impossible")
    else:
        for row in grid:
            print("".join(row))


cases = int(inputf.readline())
for case in range(1, cases+1):
    print("Case #"+str(case)+":")

    r, c, m = (int(x) for x in inputf.readline().split(" "))
    do_case(r, c, m)


#for r in range(1, 10):
#    for c in range(1, 10):
#        for m in {r-1, c-1}:
#            print(r, c, m)
#            do_case(r, c, m)
#            input()
