import sys
sys.stdin = open('F:/Desktop/A-large.in' , 'r')
sys.stdout = open('F:/Desktop/a.out' , 'w')
sys.setrecursionlimit(2000) 

def f(r , adj) :
    vis = [False for x in range(len(adj))]
    f.result = False
    
    def dfs(x) :
        if(vis[x] == False) :
            vis[x] = True
            for y in adj[x] :
                dfs(y)
        else :
            #print("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!")
            f.result = True
    
    dfs(r)
    return f.result

T = int(input())
for case in range(T) :
    adj = [[],]
    
    N = int(input())
    for i in range(N) :
        L = input().split()
        adj.append([int(x) for x in L[1:]])
    
    _adj = [[] for i in range(N + 1)]
    for x in range(1 , len(adj)) :
        for y in adj[x] :
            _adj[y].append(x)
    
    roots = []
    for x in range(1 , len(_adj)) :
        if(len(_adj[x]) == 0) :
            roots.append(x)
    #print(roots) #
    
    result = False
    for x in roots :
        if f(x , adj) == True :
            result = True
            break
    
    print ('Case #%d:'%(case + 1) , 'Yes' if result else 'No')


        
        