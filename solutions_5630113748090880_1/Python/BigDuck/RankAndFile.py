from collections import deque
import sys




f = open("input")
nOfCase = int(f.readline())


for i in xrange(nOfCase):
    N = int(f.readline())
    d = {}
    for j in xrange(2*N-1):
        row = [int(x) for x in f.readline().strip().split()]
        #print row
        for x in row:
            d[x]=d.get(x,0)+1
    lst = []
    for x in d.items():
        #print x
        if x[1] % 2 != 0:
            lst.append(x[0])
    #lst = x[0] if x[1] %2 != 0 for x in d.items
    lst.sort()
    sys.stdout.write("Case #%d: " % (i+1))
    for elem in lst[0:-1]:
        sys.stdout.write(str(elem)+" ")
    sys.stdout.write(str(lst[-1]))
    sys.stdout.write('\n')
