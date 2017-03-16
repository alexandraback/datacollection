def reprPank(p):
    out = 0
    for c in p[::-1]:
        out <<= 1
        if c:
            out+=1
    return out

def flip(pk,pos, fullPank):
#    return ((~(pk % (1<<(pos+1)))) & fullPank) | \
#        (pk >> (pos+1) << (pos+1))
    filt = (1<<(pos+1)) - 1
    return (~pk) & filt | (pk & (~filt))


def solveCase():
    origPank = [ c=='+' for c in input() ]
    pkLen = len(origPank)
    pank = reprPank(origPank)
    fullPank = (1<<(pkLen))-1
    qu = [ (pank,0) ]
    seen = [ False for p in range((1<<pkLen)+42) ]

#    print(bin(pank),bin(fullPank))
    while not qu == []:
        pank,depth = qu.pop(0)
#        print('',bin(pank))
        
        if pank == fullPank:
            return depth

        if seen[pank]:
#            print("\tseen.")
            continue
        seen[pank] = True

        for flipPos in range(pkLen):
            qu.append( (flip(pank, flipPos, fullPank), depth+1) )
    return -1

T = int(input())
for c in range(T):
    print("Case #{}: {}".format(c+1,solveCase()))
