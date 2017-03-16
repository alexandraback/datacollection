import sys,copy

input = []
for i,line in enumerate(sys.stdin):
    if i == 0:
        n = int(line.strip('\r\t\n '))
    else:
        input.append(line.strip('\r\t\n '))
assert n*3 == len(input)

def lowerbound(k,target):
    ret = None
    for y in target:
        if y < k and ( ret == None or y > ret ):
            ret = y
    return ret
        
def upperbound(k,target):
    ret = None
    for y in target:
        if y > k and (ret == None or y < ret):
            ret = y
    return ret

template='Case #%d: %d %d'

for i in xrange(n):
    b = int(input[3*i] )
    noami = [float(t) for t in input[3*i + 1].split(' ')]
    ken1 = [float(t) for t in input[3*i + 2].split(' ')]
    ken2 = copy.deepcopy(ken1)
    
    deceitscore = 0
    truescore = 0 
    for k in sorted(noami,reverse=True):
        j = lowerbound(k, ken1)
        if j == None: break
        else:
            ken1.remove(j)
            deceitscore += 1
    for s,k in enumerate(sorted(noami,reverse=False)):
        j = upperbound(k,ken2)
        if j == None:
            truescore = len(noami) - s
            break
        else:
            ken2.remove(j)
    print template%(i+1, deceitscore, truescore)
