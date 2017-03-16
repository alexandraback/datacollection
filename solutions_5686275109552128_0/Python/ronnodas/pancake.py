def best(counts):
    N = max(counts.keys())
    if N <= 3:
        return N
    highcount = counts[N]
    new = {n:c for n,c in counts.items()}
    del new[N]
    for i in (N//2,(N+1)//2):
        if i in new:
            new[i]+= highcount
        else:
            new[i] = highcount
    return min(best(new)+highcount,N)

T = int(input())
for case in range(1,T+1):
    D = int(input())
    PS = [int(x) for x in input().split()]
    counts = {}
    for p in PS:
        if p not in counts:
            counts[p] = 1
        else:
            counts[p] += 1
    ans = best(counts)
    print("Case #",case,": ",ans,sep = '')
