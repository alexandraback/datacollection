import sys;

visited = 0;
    
def isDiamond(c,adj):
    global visited;
    for i in adj[c]:
        if isDiamond(i-1,adj):
            return True;
        elif visited[i-1]:
            return True;
        else:
            visited[i-1]=True;
            
    return False;
    
    
with open(sys.argv[1],'r') as f:
    T=int(f.readline().strip('\n'));
    for t in range(0,T):
        C=int(f.readline().strip('\n'));
        indegree=[0]*C;
        adj=[];
        
        
        for c in range(0,C):
            adj.append([int(i) for i in f.readline().strip('\n').split()[1:]]);
            for i in adj[-1]:
                indegree[i-1]+=1;
            
        for c in range(0,C):
            if indegree[c] == 0:
                visited =[False]*C;
                if isDiamond(c,adj):
                    print "Case #%d: Yes"%(t+1);
                    break;
        else:
            print "Case #%d: No"%(t+1);
                    

