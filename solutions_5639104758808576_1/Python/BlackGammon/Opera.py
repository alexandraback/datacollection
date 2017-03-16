from sys import *

def readval(fi, ty): return ty(fi.readline())
def readtab(fi, ty): return tuple(map(ty, fi.readline().split()))

fi = open(argv[1], 'r')
T = readval(fi, int)
for k in range(T):
    S0, val0 = readtab(fi, str)
    S = int(S0)
    val = [int(val0[i]) for i in range(S+1)]
    ami = 0
    debout = 0
    for i in range(S+1):
        debout += val[i]
        if debout < i + 1:
            ami += i + 1 - debout
            debout = i +1
    print "Case #"+str(k+1)+": "+str(ami)
    