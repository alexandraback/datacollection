T = int(input())

def solve(K,C,S):
    return range(1,K+1)

for t in range(T):
    K,C,S = [int(x) for x in input().split()]
    print("Case #%d: %s" % (t+1, ' '.join([str(x) for x in solve(K,C,S)])))
    
