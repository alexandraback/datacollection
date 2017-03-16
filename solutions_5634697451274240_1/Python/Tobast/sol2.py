import sys

def reprPank(p):
    out = 0
    for c in p[::-1]:
        out <<= 1
        if c:
            out+=1
    return out

def flip(pk,pos): # ...which is commutative.
    return pk ^ ((1<<(pos+1))-1)

def optiFlips():
    origPancake = [ c=='+' for c in input() ]
    size = len(origPancake)
    pank = reprPank(origPancake)
    flips = 0
    for pos in range(size-1,-1,-1):
        if(pank & (1<<pos)) == 0:
            pank = flip(pank, pos)
            flips += 1
    if(pank != (1<<size)-1):
        print("ERROR: not succeded: {}, exp {}".format(\
                bin(pank),bin((1<<size)-1)), file = sys.stderr)
    return flips

T = int(input())
for c in range(T):
    print("Case #{}: {}".format(c+1, optiFlips()))
