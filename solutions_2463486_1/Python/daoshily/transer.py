import math
infile = open('C-large-1.in','r')
outfile = open('C.out','w')
n = int(infile.readline())
print >> outfile,n
for i in range(0,n):
    tmp = infile.readline().split(' ')
    A = int(tmp[0])
    print >> outfile, int(math.sqrt(A-1)),
    B = int(tmp[1])
    print >> outfile, int(math.sqrt(B))
infile.close()
outfile.close()
