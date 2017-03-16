import math as math
from collections import defaultdict
f = open("C-small-attempt2.in")
tests = int(f.readline())
for t in range(tests):
    jpsk = f.readline().split(" ")
    jackets = int(jpsk[0])
    pants = int(jpsk[1])
    shirts = int(jpsk[2])
    maxDoubles = int(jpsk[3])

    d1 = defaultdict(int)
    d2 = defaultdict(int)
    d3 = defaultdict(int)

    
    toPrint = ""
    count = 0
    for i in range(shirts):
        for j in range(pants):
            for k in range(jackets):
                d1[(k+1, j+1)] += 1
                d2[(j+1, i+1)] += 1
                d3[(i+1, k+1)] += 1
                if(not (d1[(k+1, j+1)] > maxDoubles or d2[(j+1, i+1)] > maxDoubles or d3[(i+1, k+1)] > maxDoubles)):
                    toPrint += "%d %d %d" % (k+1, j+1, i+1)
                    toPrint += "\n"
                    count += 1
                else:
                    d1[(k+1, j+1)] -= 1
                    d2[(j+1, i+1)] -= 1
                    d3[(i+1, k+1)] -= 1
    print("Case #%d: %d"%(t+1, count))
    print(toPrint, end="")
