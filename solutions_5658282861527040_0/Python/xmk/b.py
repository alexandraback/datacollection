import sys
f = open("b0" if len(sys.argv)<2 else sys.argv[1] ,"r")
T = int(f.readline())
def work(A,B,K):
    cnt = 0
    for a in range(A):
        for b in range(B):
           if a&b < K:
               cnt+=1
    return cnt

    
    

for t in range(1,1+T):
    A,B,K = tuple(map(int, f.readline().split()))
    #print(A,B,K)
    r = work(A,B,K)    
    print("Case #%d: %s"%(t, r ))
