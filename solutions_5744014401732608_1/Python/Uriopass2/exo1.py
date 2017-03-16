import math as math
f = open("B-large.in")
tests = int(f.readline())
for t in range(tests):
    bAndM = [int(x) for x in f.readline().split(" ")]
    b = bAndM[0]
    m = bAndM[1]
    if(m == 1):
        logm = 0
    else:
        logm = int(math.log2(m-1))
    slides = [[0 for x in range(b)] for y in range(b)]
    
    if(math.log2(m) > b-2):
        print("Case #%d: IMPOSSIBLE"%(t+1))
    else:
        print("Case #%d: POSSIBLE"%(t+1))
        for x in range(b-1):
            slides[x][x+1] = 1
        for x in range(b-2-logm, b):
            for y in range(x+1, b):
                slides[x][y] = 1
        if(m > 1):
            for x in range(b-2-logm, b):
                value = 1 if x == b-1 else 2**(b-x-2)
                #print(m, value)
                #print(b-logm-3)
                if(m >= value):
                    m -= value
                    slides[b-logm-3][x] = 1
        for x in range(b):
            for y in range(b):
                print(slides[x][y], end='')
            print("")


