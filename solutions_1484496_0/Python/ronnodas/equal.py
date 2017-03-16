T=int(input())
for t in range(T):
    N = 2**20
    print('Case #',t+1,':',sep = '')
    ns = [int(x) for x in input().split()][1:]
    sums = {}
    ns.sort()
    for i in range(1,N):
        s = 0
        for d in range(20):
            if i&(1<<d):
                s+= ns[d]
        if s in sums:
            j = sums[s]
            for k in [j,i]:
                ls = []
                for d in range(20):
                    if k&(1<<d):
                        ls.append(ns[d])
                print(*ls)
            break
        else:
            sums[s] = i
    else:
        print("Impossible")
