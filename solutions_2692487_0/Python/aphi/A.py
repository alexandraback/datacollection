import sys

fp = open(sys.argv[1], "r")

lines = fp.readlines()

fpOut = open("outputA.txt", "w")

numCases = int(lines.pop(0).strip())

for c in range(1, numCases+1):
    A, N = lines.pop(0).strip().split(" ")
    A, N = int(A), int(N)
    
    motes = sorted(map(int, lines.pop(0).strip().split(" ")))

    if A == 1:
        costs = [N]
    else:    
        adds = 0
        costs = []
        
        for i, m in enumerate(motes):
            # calculate cost pre this mote
            # cost = all adds up to here + deletion of rest        
                    
            cost = adds + N - i
            costs.append(cost)
            
            #simulate the add required to move forward               
            while A <= m:
                A += A - 1
                adds += 1
                
            A += m
            
        costs.append(adds) # all adds
            
    outString = "Case #%d: %d\n"%(c, min(costs))
    print outString,
    fpOut.write(outString)
    
fpOut.close()