#!/usr/bin/python3



def getGScore(C, W):
    if C % W == 0:
        return C//W + W-1
    else:
        return C//W + W


T = int(input())

for t in range(T):
    
    R, C, W = tuple(map(int, input().split()))
    
    if R != 1:
        raise RuntimeError("unexpected number of rows")
    
    print("Case #%d: %d" % (t+1, getGScore(C, W)))



