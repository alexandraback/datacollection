import heapq
vis = {}
def bfs(x,y):
	hp = []
	heapq.heappush(hp,[1,[0,0],""])
	while (len(hp)):
		curr =heapq.heappop(hp)
		if (str(curr[1]) in vis):
			continue;
		vis[str(curr[1])] = 1
		
		if (curr[1]==[x,y]):
			return curr[2]
		heapq.heappush(hp,[curr[0]+1,[curr[1][0]+curr[0],curr[1][1]],curr[2]+'E'])
		heapq.heappush(hp,[curr[0]+1,[curr[1][0]-curr[0],curr[1][1]],curr[2]+'W'])
		heapq.heappush(hp,[curr[0]+1,[curr[1][0],curr[1][1]+curr[0]],curr[2]+'N'])
		heapq.heappush(hp,[curr[0]+1,[curr[1][0],curr[1][1]-curr[0]],curr[2]+'S'])

T = int(raw_input())
for i in range(T):
	tx,ty = map(int,raw_input().split())
	vis = {}
	print "Case #"+str(i+1)+": "+bfs(tx,ty)