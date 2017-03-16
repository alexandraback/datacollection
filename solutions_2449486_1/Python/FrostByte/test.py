results = ["NO", "YES"]

def cut(level, array, n, m):

    grid = [[0 for j in range(m)] for i in range(n)]
    cut  = [[0 for j in range(m)] for i in range(n)]

    row    = [0 for i in range(n)]
    column = [0 for i in range(m)]

    uncut = 0

    for i in range(n):
        for j in range(m):
            if array[i][j] <= level:
                grid[i][j] = 1
                uncut += 1

    for i in range(n):
        for j in range(m):
            row[i] += grid[i][j]
            column[j] += grid[i][j]

    for i in range(n):
        if row[i] == m:
            for j in range(m):
                if cut[i][j] == 0:
                    cut[i][j] = 1
                    uncut -= 1

    for j in range(m):
        if column[j] == n:
            for i in range(n):
                if cut[i][j] == 0:
                    cut[i][j] = 1
                    uncut -= 1

    if uncut == 0:
        return 1
        
    return 0

def compute(array, n, m):
    
    max = array[0][0]
    min = array[0][0]

    for i in range(n):
        for j in range(m):
            if array[i][j] < min : min = array[i][j]
            if array[i][j] > max : max = array[i][j]

    sweep = range(min, max+1)[::-1]
    for i in sweep:
        if(cut(i,array,n,m) == 0):
            return 0

    return 1

def do_thing(index):

    n,m = raw_input().split()
    n,m = int(n), int(m)
    
    array = [[int(x) for x in raw_input().split()] for i in range(n)]

    result = compute(array, n, m)
    print "Case #%d: %s" % (index + 1, results[result])
    
n = raw_input()
n = int(n)

for i in range(n):
    do_thing(i)

