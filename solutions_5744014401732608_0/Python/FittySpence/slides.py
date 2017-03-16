from __future__ import print_function

def drawstring(mat, b):
    out = ""
    for i in range(1, b):
        for j in range(0, b):
            out = out + str(mat[i][j])
        out = out + "\n"
    return out
    

f = open('C:\\Users\\djspence\\Downloads\\B-small-attempt0c.in', 'r')
#f = open('C:\\Users\\djspence\\Downloads\\testing.in', 'r')

f2 = open('C:\\Users\\djspence\\Documents\\Miscellaniety\\codejam2016\\slidessoln.txt', 'w')

tries = int(f.readline())

soln = ""

for t in range(0, tries):
    soln = soln + "Case #" + str(t + 1) + ": "
    vals = f.readline().split()
    
    b = int(vals[0])
    m = int(vals[1])
    
    mat = [[0 for i in range(0, b)] for j in range(0, b)]
    for i in range(1, b):
        for j in range(i + 1, b):
            mat[i][j] = 1
    
    if m > 2**(b - 2):
        soln = soln + "IMPOSSIBLE\n"
        continue
    
    soln = soln + "POSSIBLE\n"
    
    if m == 2**(b - 2):
        endstring = ""
        for j in range(0, b - 1):
            endstring = endstring + "1"
        l = len(endstring)
        for j in range(0, b - l):
            endstring = "0" + endstring
    else:
        endstring = bin(m)[2:]
        endstring = endstring + "0"
        l = len(endstring)
        for j in range(0, b - l):
            endstring = "0" + endstring
            
    soln = soln + endstring + "\n" + drawstring(mat, b)

print(soln, file = f2)
f2.close()