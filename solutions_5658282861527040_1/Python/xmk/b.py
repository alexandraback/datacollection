import sys
f = open("b1" if len(sys.argv)<2 else sys.argv[1] ,"r")
T = int(f.readline())
def work(A,B,K):
    cnt = 0
    for a in range(A):
        for b in range(B):
           if a&b < K:
               cnt+=1
    return cnt

def work2(A,B,K):
    b = 1
    ma = max(A,B)
    if ma <= K:
        return (A+1)*(B+1)

    while b <= ma:
        b<<=1
    m = b-1
    b >>=1
    rtn = 0
    Ab=A&b
    Bb=B&b
    if Ab and Bb:
        if K >= b:
            rtn += b*(A+B-b+2)
            rtn += work2(A-b, B-b, K-b)
        else:
            rtn += work2(b-1, b-1, K)
            rtn += work2(b-1, B-Bb , K)
            rtn += work2(A-Ab, b-1 , K)
    elif Ab:        
        rtn += work2(b-1, B, K)        
        rtn += work2(A-b, B, K)
    else:
        rtn += work2(A, b-1, K)        
        rtn += work2(A, B-b, K)
    return rtn

def work3(A,B,K):
    return work2(A-1,B-1,K-1)
for t in range(1,1+T):
    A,B,K = tuple(map(int, f.readline().split()))
    #print(A,B,K)
    #r = work(A,B,K)
    r = work3(A,B,K)
    print("Case #%d: %s"%(t, r ))
# work(10**6,10**6,10**6)
# print("done")
