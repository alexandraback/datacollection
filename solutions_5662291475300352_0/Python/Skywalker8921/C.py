import sys,math

def main_small1(N,H):
    ## At most 2 hikers
    if N == 2:
        H1 = H[0]
        H2 = H[1]
    else:
        if H[0][1] <= 1:
            return 0
        H1 = H[0]
        H2 = (H[0][0],H[0][1],H[0][2]+1)
    if H2[2] < H1[2] : ## H1 is supposed the fastest
        H1,H2 = H2,H1
    vr = 360 / H1[2]
    vl = 360 / H2[2]
    print("vl={},vr={}".format(vl,vr),file=sys.stderr)
    pr = H1[0]
    pl = H2[0]
    if pl < pr:
        t = (pl-pr)
    t2 = (360+pl-pr)/(vr-vl)
    Tl = (360-pl)/vl
    print("t2={},Tl={}".format(t2,Tl),file=sys.stderr)
    if t2 > Tl:
        return 0
    else:
        return 1

if __name__ == "__main__":
    T = int(input())
    for c in range(T):
        ## Input
        N = int(input())
        H = []
        for _ in range(N):
            H.append(tuple([int(i) for i in input().split()]))
        ## Processing
        res = main_small1(N,H)
        ## Output
        print("Case #{}: {}".format(c+1,res))


