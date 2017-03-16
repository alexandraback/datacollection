import time
filename = 'C-small-attempt0'
with open(filename + '.in', 'r') as f:
    data_raw = f.readlines()
f.closed

starttime = time.time()

data_raw = data_raw[1:]

outputs = []

def evaluate(n, D, V):
    D2 = list(D)
    Vmax = len(V) - 1
    while len(D2):
        d = D2.pop(0)
        n2 = n + d        
        if(n2 > Vmax):
            break
        V[n2] = True
        evaluate(n2, D2, V)
            
    

def solve(input):
    C, Dn, Vmax = input[0]
    D = input[1]
    
    V = [False] * (Vmax + 1) #prevent 0 index problems
    V[0] = True

    evaluate(0, D, V)
    i = 0
    v = True
    added = 0
#    debug = []
    while True:
        v = True
        while v and i < Vmax:
            i += 1
            v = V[i]
        
        if v:
            break
                
        V2 = list(V)
        added += 1
   #     debug.append(i)
        V[i] = True
        for j in xrange(Vmax + 1 - i):
            if(V2[j]):
                V[j + i] = True
            
    #print debug
    return added

p = True
for line in data_raw:
    if p:
        line1 = [int(x) for x in line.strip().split(' ')]
    else:
        line2 = [int(x) for x in line.strip().split(' ')]
        outputs.append(solve((line1, line2)))
    p = not p

with open(filename + '.out', 'w') as f:
    i = 1
    outputstrings= []
    for output in outputs:
        outputstrings.append('Case #{0}: {1}'.format(i, output, output))
        i += 1
    f.write('\n'.join(outputstrings))
f.closed

print time.time() - starttime