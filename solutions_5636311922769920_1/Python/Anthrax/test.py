T = int(input())

def solve(K,C,S):
    if K == 1:
        return [1];
    if C == 1:
        if K == S:
            return range(1,K+1)
        else:
            return None

    if S < K-1:
        return None
    else:
        return range(2,K+1)
for t in range(T):
    K,C,S = [int(x) for x in input().split()]
    ans = solve(K,C,S)
    if ans != None:
        print("Case #%d: %s" % (t+1, ' '.join([str(x) for x in ans])))
    else:
        print("Case #%d: %s" % (t+1, "IMPOSSIBLE"))
    
    
