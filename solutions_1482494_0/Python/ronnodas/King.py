import heapq

T=int(input())
for t in range(T):
    n = int(input())
    done = [[0,0] for i in range(n)]
    reqs = []
    for i in range(n):
        reqs.append(tuple([int(x) for x in input().split()]))

    avail = [0]*2005
    for (a,b) in reqs:
        avail[a]+=1
        avail[b]+=1
    stars = 0
    s1h = [(r[0],r[1],i,0) for (i,r) in enumerate(reqs)]
    s2h = [(r[1],i) for (i,r) in enumerate(reqs)]
    heapq.heapify(s1h)
    heapq.heapify(s2h)
    count = 0
    cando = avail[0]
#    print(avail)
    while (s1h or s2h):
#        print(s1h,s2h,count,stars,cando)
        if s2h and s2h[0][0]<=stars:
            r,i = heapq.heappop(s2h)
            if done[i][0]:
                continue
            done[i]=[1,1]
            stars+=2
            cando+=avail[stars-1]+avail[stars]-2
            count+=1
        elif s1h and s1h[0][0]<=stars:
            r,s,i,type = heapq.heappop(s1h)
            if done[i][type]:
                continue
            if (not done[i][0]) and (reqs[i][1]<=stars+cando-(reqs[i][1]>stars)):
                continue
            stars+=1
            cando+=avail[stars]-1
            count+=1

            if done[i][0]:
                done[i][1] = 1
            else:
                heapq.heappush(s1h,(reqs[i][1],-1,i,1))
                done[i][0]=1
        else:
            ans = "Too Bad"
            break
    else:
        ans = count
    print('Case #',t+1,': ',ans,sep = '')
