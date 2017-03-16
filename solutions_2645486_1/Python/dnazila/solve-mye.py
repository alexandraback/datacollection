import sys
#I used r and t variables with the wrong name

fname = sys.argv[1]

f = open(fname, "rt")

T = int(f.readline())

def calc_value(V, NL, E, R):
    p = 0
    C = E
    #print "E %d R %d" % (E, R)
    for i in range(len(V)):
        if NL[i] == -1:
            e_to_burn = C
        else:
            e_to_burn = min(max(C + NL[i] * R - E, 0), C)
        
        p += e_to_burn * V[i]
        C += (R - e_to_burn)
        C = min(C, E)
        #print "burn %d gain %d refill %d" %(e_to_burn, e_to_burn * V[i], C)

    return p
        


def handle_case(f, caseno):
    line = f.readline()
    fields = line.split()
    E = int(fields[0])
    R = int(fields[1])
    N = int(fields[2])
    line = f.readline()
    V = map(int, line.split())
    NL = [-1 for i in range(len(V))]
    blocks = []
    for i in range(1, len(V)):
        if V[i] > V[i-1]: #all the action happens here
            NL[i-1] = 1
            for block_idx in reversed(range(len(blocks))): #reversed to be able to remove items
                #print blocks[block_idx]
                while blocks[block_idx][1] >= blocks[block_idx][0] and V[blocks[block_idx][1]] <= V[i]:
                    NL[blocks[block_idx][1]] = i - blocks[block_idx][1]
                    blocks[block_idx][1] -= 1

                if blocks[block_idx][1] < blocks[block_idx][0]:
                    del blocks[block_idx]
                    
        else:
            if len(blocks) > 0:
                if blocks[-1][1] == i-1:
                    blocks[-1][1] = i
                else:
                    blocks.append([i-1, i])
            else:
                blocks.append([i-1, i])
        #print caseno, blocks, NL
    
        
    #print NL


    print "Case #%d: %d" % (caseno, calc_value(V, NL, E, R))


    



    
    

        

for case in range(T):
    handle_case(f, case+1)
        

    
