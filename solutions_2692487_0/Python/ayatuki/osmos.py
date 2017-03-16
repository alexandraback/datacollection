import sys, os

lines = [line.rstrip() for line in open(sys.argv[1])]
tNum = int(lines[0])
lines.pop(0)

dataSet = []
count = 1

while len(lines) != 0:
    (A, N) = [int(v) for v in lines.pop(0).split()]
    Ns = [int(v) for v in lines.pop(0).split()]
    dataSet.append( (count, (A,N,Ns)) )
    count += 1

def osmos(a, i, ns, memo):
    if (a,i) in memo:
        return memo[(a,i)]
    if (len(ns) == i):
        return 0
    if ( a > ns[i] ):
#        print("ok")
        v = osmos(a + ns[i], i+1, ns, memo)
    else:
#        print('{0},{1},{2}'.format(a,i,ns))
        if (a - 1) == 0:
            v = osmos(a, i+1, ns, memo) + 1
        else:
            add = osmos(a + (a-1), i, ns, memo) + 1
            dele = osmos(a, i+1, ns, memo) + 1
            v = min(add, dele)
    memo[(a,i)] = v
    return v

def solv(A, N, Ns):
    Ns.sort()
#    print('{0},{1},{2}'.format(A,N,Ns))
    return osmos( A, 0, Ns, {} )

for (i,data) in dataSet:
    print('Case #{0}: {1}'.format(i, solv(data[0],data[1],data[2])))
