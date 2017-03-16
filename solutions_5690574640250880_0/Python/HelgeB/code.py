'''
Created on 15.03.2014

@author: Helge
'''

def myprint(matrix):
    for r in matrix:
        for c in r:
            output.write(c)
        output.write('\n')
    #output.write('\n')

file = open('C-small-attempt2.in', 'r')
output = open('output', 'w')

numberOfTestcases = file.readline()

for counter in range(0, int(numberOfTestcases)):
    line = file.readline().replace('\n', '').split(' ')
    R = int(line[0])
    C = int(line[1])
    M = int(line[2])
    
    N = R*C-M
    
    grid = [['.' for _ in range(C)] for _ in range(R)]
    
    impossible = 0
    if N == 1:
        grid = [['*' for _ in range(C)] for _ in range(R)]
        grid[0][0] = 'c'
    elif R == 1 or C == 1:
        grid[0][0] = 'c'
        if R == 1:
            for i in range(C-M, C):
                grid[0][i] = '*'
        else:
            for i in range(R-M,R):
                grid[i][0] = '*'
        
    elif R == 2 or C == 2:
        if N%2==1 or N < 4:
            impossible = 1
        else:
            grid[0][0] = 'c'
            if R == 2:
                for i in range(C-int(M/2), C):
                    grid[0][i] = '*'
                    grid[1][i] = '*'
            else:
                for i in range(R-int(M/2),R):
                    grid[i][0] = '*'
                    grid[i][1] = '*'
    else:
        if N < 4 or N == 5 or N == 7:
            impossible = 1
        else:
            grid = [['*' for _ in range(C)] for _ in range(R)]
            grid[0][0] = 'c'
            grid[1][0] = '.'
            grid[0][1] = '.'
            grid[1][1] = '.'
            
            if N > 4:
                grid[0][2] = '.'
                grid[1][2] = '.'
                if N > 6:
                    grid[2][1] = '.'
                    grid[2][0] = '.'
                    rest = N - 8
                    j = 3
                    while rest >= 2 and j<R:
                        grid[j][1] = '.'
                        grid[j][0] = '.'
                        rest = rest - 2
                        j = j + 1
                    j = 3
                    while rest >= 2 and j<C:
                        grid[1][j] = '.'
                        grid[0][j] = '.'
                        rest = rest - 2
                        j = j + 1      
                    k = 2
                    l = 2          
                    while rest > 0:
                        grid[k][l] = '.'
                        rest = rest - 1
                        if k + 1 < R:
                            k = k + 1
                        else:
                            k = 2
                            l = l + 1                

    output.write('Case #' + str(counter+1) + ':\n')     
    if impossible == 1:
        output.write('Impossible\n')
    else:
        myprint(grid)
    
    
 
    
