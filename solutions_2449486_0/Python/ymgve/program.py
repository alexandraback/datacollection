import sys

import psyco; psyco.full()

def main():
    f = open(sys.argv[1], "rb")
    ncases = int(f.readline())
    for caseno in xrange(ncases):
        y, x = f.readline().strip().split()
        y = int(y)
        x = int(x)
        
        grid = []
        dest = []
        for i in xrange(y):
            row = []
            for n in f.readline().strip().split():
                row.append(int(n))
            grid.append(row)
            dest.append([False] * x)
            
        for i in xrange(x):
            tallest = 0
            for j in xrange(y):
                tallest = max(tallest, grid[j][i])
                
            for j in xrange(y):
                if grid[j][i] == tallest:
                    dest[j][i] = True
                    
        for i in xrange(y):
            tallest = 0
            for j in xrange(x):
                tallest = max(tallest, grid[i][j])
                
            for j in xrange(x):
                if grid[i][j] == tallest:
                    dest[i][j] = True
            
        s = "YES"
        for row in dest:
            if False in row:
                s = "NO"
                break
            
        print "Case #%d: %s" % (caseno+1, s)
        
main()