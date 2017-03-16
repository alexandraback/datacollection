from sys import argv

def solve(C, W):
    if C == W:
        return W
    res = 0
    while C > 2*W:
        res += 1
        C -= W
    res += W +1
    return res
    
with open(argv[1]) as f:
    T = int(f.readline())
    for i in range(T):
        R, C, W = [int(val) for val in f.readline().split()]
        res = max((C / W)*(R-1),0)
        res += solve(C, W)
        print ("Case #"+str(i+1)+": "+str(res))
    
