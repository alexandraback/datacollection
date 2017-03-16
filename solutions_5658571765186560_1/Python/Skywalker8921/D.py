import sys,math

def main_small(X,R,C):
    crit1 = (R*C)%X == 0        # obviously needed
    crit2 = (R >= X or C >= X)  # otherwise a line won't fit
    h = math.ceil(X/2)
    crit3 = (R >= h and C >= h) # otherwise a L won't fit
    crit4 = X < 7 # starting at 7 there are ominoes with small holes
    crit5 = X < 4 or (R >= 3 and C >= 3) # for the S omino
    crit6 = X < 5 or (R >= 4 and C >= 4) # for X=5, avoid the +,
                                         # for X=6, avoid the S
    return crit1 and crit2 and crit3 and crit4 and crit5 and crit6

if __name__ == "__main__":
    T = int(input())
    for c in range(T):
        X,R,C = [int(i) for i in input().split()]
        res = main_small(X,R,C)
        #res = main_large(X,R,C)
        if res:
            resprt = "GABRIEL"
        else:
            resprt = "RICHARD"
        print("Case #{}: {}".format(c+1,resprt))
        print("Case #{}: {} in {}x{} : {}".format(c+1,X,R,C,resprt),
              file=sys.stderr)
        
