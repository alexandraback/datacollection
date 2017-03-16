import numpy

problem = 'C-large'

fin = open(problem + '.in')
fout = open(problem + '.out', 'w')

def read_ints():
    return [int(x) for x in fin.readline().strip().split()]

#def format_grid(grid):
#    return '\n'.join(''.join(line) for line in grid)

def is_grid_solvable(grid, M):
    R, C = grid.shape
    if R == 2:
        if M % 2 == 0:
            minecols = M//2
            grid[:, -minecols:] = 1
            return True
        else:
            return False
    
    if M < R + C -1:
        ...
    
    if is_grid_solvable(grid[:-1], M-R):
        grid[-1, :] = 1
        return True
    
    elif is_grid_solvable(grid[:, :-1], M-C):
        grid[:, -1] = 1
        return True
    
    return False

def format_grid(grid):
    chars = {1.0:'*', 0.0:'.', -1.0:'c'}
    return '\n'.join(''.join(chars[n] for n in row) for row in grid)

def clear_grid(grid, M):
    R, C = grid.shape
    # We can assume R <= C
    S = R*C - M # Spaces without mines
    print(R, C, S)
    
    if M == 0:
        grid[:, :] = 0.0
        return True
    
    if S == 1:
        grid[0, 0] = 0.0
        return True
    
    if R == 1:
        grid[0, :S] = 0.0
        print('dim 1', S)
        print(repr(grid))
        return True
    
    for rx in range(2, C+1):
        for ry in range(2, R+1):
            r = ry*rx
            rem = S - r
            if rem < 0:
                break
            if rem > rx+ry:
                continue
            
            if rem == 1:
                # No way to position 1 on a rectangle, and the next will be too big
                break
            
            if rem <= ry and rx < C:
                grid[:ry, :rx] = 0.0
                grid[:rem, rx] = 0.0
                print("beside", rx, ry, rem)
                return True
            
            if rem <= rx and ry < R:
                grid[:ry, :rx] = 0.0
                grid[ry, :rem] = 0.0
                print("below", rx, ry, rem)
                return True
            
            if (ry < R) and (rx < C):
                fillbeside = ry
                fillbelow = rem - ry
                if fillbelow == 1:
                    if fillbeside == 2:
                        continue
                    fillbeside -= 1
                    fillbelow += 1
                grid[:ry, :rx] = 0.0
                grid[ry, :fillbelow] = 0.0
                grid[:fillbeside, rx] = 0.0
                print("both", rx, ry, rem)
                print(fillbeside, fillbelow)
                return True
    
    return False
    
T = read_ints()[0]
for caseno in range(1, T+1):
    print('Case %d ---------' % caseno)
    R, C, M = read_ints()
    
    grid = numpy.ones((R, C))
    
    if R > C:
        poss = clear_grid(grid.T, M)
    else:
        poss = clear_grid(grid, M)
        
    
    fout.write("Case #%d:\n" % caseno)
    if poss:
        grid[0, 0] = -1.0
        fout.write(format_grid(grid))
    else:
        fout.write('Impossible')
    fout.write('\n')