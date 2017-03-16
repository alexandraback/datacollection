import sys

def recycle(num, B):
    x = str(num)
    recycles = []
    for ii in range(1, len(x)):
        poten = int(x[ii:] + x[:ii])
        if poten > num and poten <= B and poten not in recycles:
            recycles.append(poten)    
    return len(recycles)

f = open(sys.argv[1])
T = int(f.readline())
for t in range(T):
    A, B = map(int, f.readline().split())
    total = 0
    for ii in range(A,B):
        total += recycle(ii, B)
    print "Case #%d:" % (t + 1), total
