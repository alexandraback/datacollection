import sys

vector = [(1,0,'E'),
          (0,1,'N'),
          (-1,0,'W'),
          (0,-1,'S')]


class Node:
    def __init__(self,x,y,l, letter,node = None):
        self.x = x
        self.y = y
        self.length = l
        self.letter = ''
        self.node = node
        

def solve(a,b):
    start = Node(130,130,1,'',None)
    openlist = []
    visited = [[False for i in xrange(1001)] for j in xrange(1001)]
    
    openlist.append(start)
    
    visited[130][130] = True

    ## Origin is (100,100) in visited

    l = 1 ## length

    while len(openlist) != 0:
        top = openlist[0]
        del(openlist[0])
        #l += 1

        for direction in vector:
            moved = [[top.x + direction[0]*(top.length), top.y],
                     [top.x, top.y + direction[1]*(top.length)]]
            ## You either go left/right or up/down
            
            for move in moved:
                #top.length += 1
                #l += 1
                letter = direction[2]
                u = move[0]
                v = move[1]

                if u >= 0 and u <= 1000 and v >= 0 and v <= 1000 and visited[u][v] == False:
                #print u,v

                    if u == a + 130 and v == b + 130:
                        path = []
                        path = path + [top.letter]
                        while top.node != None:
                            top = top.node
                            path = path + [top.letter]
                        path.reverse()
                        
                        s = ''.join([i for i in path])
                        s += letter
                    
                        return s
                
                    else:
                        visited[u][v] = True
                        #print letter
                        n = Node(u,v, top.length + 1, letter, top)
                        n.letter = letter
                        openlist.append(n)
            #top.length += 1
            #l += 1
        #top.length += 1
        
        
    return -1

k = 1
T = int(sys.stdin.readline())
for casenum in xrange(T):
    a = map(int,sys.stdin.readline().strip().split(' '))
    x,y = a[0], a[1]
    b = solve(x,y)
    
    print 'Case #%d: %s' % (k, b)
    k += 1

    



