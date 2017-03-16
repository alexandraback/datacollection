def bfs(G, N):
    nodes = [1]
    
    while(True):
        cur = nodes[0]
        if(cur == N):
            return
        
        e1 = cur+1
        
        e2 = str(cur)
        e2 = e2[::-1]
        e2 = int(e2, base=10)
        
        if(e1 <= N and G[e1] == 'INF'):
            G[e1] = G[cur]+1
            nodes.append(e1)
        if(e2 <= N and G[e2] == 'INF'):
            G[e2] = G[cur]+1
            nodes.append(e2)
        
        nodes.pop(0)
        

def main():
    input1 = open('input1.txt', 'r')
    output1 = open('output1.txt', 'w')

    T = int(input1.readline())      #number of test cases
    
    for casenum in xrange(1, T + 1):
        print casenum
        line = input1.readline().strip().split(' ')
        N = int(line[0])
        
        G = ['INF'] * (N+1)
        G[1] = 1
        bfs(G, N)
        
        outstr = 'Case #' + str(casenum) + ': '
        outstr += str(G[N])
        outstr += '\n'
        output1.write(outstr)

    input1.close()
    output1.close()
  
    
    
main()