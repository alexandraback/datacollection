def read_case():
    return map(int, input().split())

def f(poses, K, C):
	if len(poses) == 1: return poses[0]
	return (poses[0]-1)*K**(C-1) + f(poses[1:], K, C-1)

def gene_groups(K, C):
    g = [list(range(i*C+1, (i+1)*C+1)) for i in range(K//C)]
    if K % C > 0:
        tail = list(range(K-K%C+1, K+1))
        tail = [1]*(C-len(tail)) + tail
        return g + [tail]
    else:
        return g

def solve(case):
    K, C, S = case
    minv = (K+C-1)//C
    if S < minv:
        return "IMPOSSIBLE"
    groups = gene_groups(K, C)
    #print(groups)
    return " ".join([str(f(gene, K, C)) for gene in groups])

T = int(input())
for t in range(T):
    case = read_case()
    result = solve(case)
    print("Case #%d: %s" % (t+1, result))
    
