from heapq import heappush,heappop

# def path(parents,N):
#     if parents[-1] == -1:
#         return "IMPOSSIBLE"
#     ret = []
#     current = (1<<N)-1
#     while current>0:
#         nxt = parents[current]
#         diff = nxt ^ current
#         for i in range(N):
#             if diff == 1<<i:
#                 ret.append(str(i+1))
#         current = nxt
#     return ' '.join(reversed(ret))

T = int(input().strip())

for case in range(1,T+1):
    K,N = (int(x) for x in input().split())
    keys = [int(x) for x in input().split()]
    start = [0]*(201) #fix to 201
    for key in keys:
        start[key] += 1
    chests = []
    for i in range(N):
        line = [int(x) for x in input().split()]
        chests.append((line[0],line[2:]))
    parents = [[] for i in range((1<<N))]
    heap = [(0,start)]
    visited = [0]*(1<<N)
    while heap:
        bitmask,keys = heappop(heap)
        #print(bitmask,keys)
        if visited[bitmask]:
            continue
        visited[bitmask] = 1
        path = parents[bitmask]
        for i in range(N):
            if not ((1<<i) & bitmask):
                ktype = chests[i][0]
                new = (1<<i) ^ bitmask
                newpath = path+[i]
                #print(bitmask, i, ktype)
                #print(keys)
                if keys[ktype] ==0 or [] < parents[new] < newpath:
                    continue
                parents[new] = newpath
                #print("best path to", new, "is now", newpath)
                newkeys = keys[:]
                newkeys[ktype] -= 1
                for key in chests[i][1]:
                    newkeys[key] += 1
                heappush(heap,(new,newkeys))
                #print("added", new,newkeys)
    path = [str(x+1) for x in parents[-1]]
    ans = ' '.join(path) if path else "IMPOSSIBLE"
    print("Case #",case,": ",ans,sep = '')
