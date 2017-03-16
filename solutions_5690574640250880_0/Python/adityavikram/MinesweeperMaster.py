import itertools
from collections import deque

if __name__=='__main__':
##    for x in itertools.combinations('ABCD', 2):
##        print(x)
    T = int(input())
    for i in range(1,T+1):
        ans = 'Case #'+str(i)+': '
        val = ''
        [R,C,M] = [int(a) for a in input().split(' ')]
        graph=[]
        canDo = False
        comb = ''
        locs = [(j,k) for j in range(R) for k in range(C)]
        isIns = lambda x,y:x<R and x>-1 and y<C and y>-1
        getNeighbors = lambda x,y:[(x+a,y+b) for a in range(-1,2) for b in range (-1,2) if ((a!=0 or b!=0) and isIns(x+a,y+b)) ]
        getMines = lambda x,y:len([n for n in getNeighbors(x,y) if n in comb])
        for comb in itertools.combinations(locs,M):
            if canDo:
                break
            graph = [['.' for x in range(C)] for y in range(R)]
            for mine in comb:
                graph[mine[0]][mine[1]]='*'
            for x in range(R):
                if canDo:
                    break
                for y in range(C):
                    vis = set([])
                    if((x,y) not in comb and not(canDo)):
                        Q = deque()
##                        graph[x][y] = 'c'
                        Q.append((x,y))
                        while(len(Q)!=0):
##                            print(len(Q))
                            nd = Q.popleft()
##                            print(nd)
                            vis.add(nd)
                            if(getMines(nd[0],nd[1])==0):
                                for nbr in getNeighbors(nd[0],nd[1]):
                                    if nbr not in vis and nbr not in comb:
                                        Q.append((nbr[0],nbr[1]))
                        if(len(vis)+M == R*C):
                            canDo= True
                            graph = [['.' for p in range(C)] for q in range(R)]
                            graph[x][y] = 'c'
                            for mn in comb:
                                graph[mn[0]][mn[1]]='*'
##                            graph[x][y] = 'c'
##                            print(graph)
                            break
                            
                        else:
                            continue
        print(ans)
        if canDo:
            for st in graph:
                print(''.join(st))
        else:
            print("Impossible")
                            
                        


            
    
