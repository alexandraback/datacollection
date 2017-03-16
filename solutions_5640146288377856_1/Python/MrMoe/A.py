#!/usr/bin/python3



def getGScore(C, W):
    if C % W == 0:
        return C//W + W-1
    else:
        return C//W + W


T = int(input())

for t in range(T):
    
    R, C, W = tuple(map(int, input().split()))
    
    print("Case #%d: %d" % (t+1, (R-1)*C//W + getGScore(C, W)))



