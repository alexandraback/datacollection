
'''
Created on Apr 12, 2013

@author: herman
'''


infile = open("input.txt","r")
outfile = open("output.txt","w")

trials = int(infile.readline())

class Snake:
    def __init__(self,R,C):
        self.R = R
        self.C = C
        self.snake = [[False for x in xrange(C)] for y in xrange(R)]
        self.skin = [[False for x in xrange(C)] for y in xrange(R)]
        self.size = 0
    def copy(self):
        s = Snake(self.R,self.C)
        s.snake = [z[:] for z in self.snake]
        s.skin = [z[:] for z in self.skin]
        s.size = self.size
        return s
    def all_neighbors(self,point):
        i,j = point
        an = []
        for dx in xrange(-1,2):
            for dy in xrange(-1,2):
                if dx != 0 or dy != 0:
                    an.append((i+dx,j+dy))
        # filter for valid points
        filtered = [(x,y) for x,y in an if (x >= 0 and x < self.R) and (y >= 0 and y < self.C)]
        return filtered
    def direct_neighbors(self,point):
        i,j = point
        dn = []
        for dx,dy in [(-1,0),(1,0),(0,-1),(0,1)]:
            dn.append((i+dx,j+dy))
        filtered = [(x,y) for x,y in dn if (x >= 0 and x < self.R) and (y >= 0 and y < self.C)]
        return filtered
    def skin_neighbors(self,point):
        return [(x,y) for x,y in self.all_neighbors(point) if self.skin[x][y]]
    def new_neighbors(self,point):
        return [(x,y) for x,y in self.all_neighbors(point) if (not self.skin[x][y]) and (not self.snake[x][y])]

    def is_skin(self,point):
        surround = [self.skin[x][y] or self.snake[x][y] for x,y in self.all_neighbors(point)]
        return not reduce(lambda a,b: a and b, surround)

    def update(self,next_point):
        i,j = next_point
        if not self.skin[i][j]:
            self.size += 1 # bonus for the first point
            
        # change the point
        self.skin[i][j] = False
        self.snake[i][j] = True
        
        # deal with neighbors
        skins = self.skin_neighbors(next_point)
        news = self.new_neighbors(next_point)
        self.size += len(news) # update size
        
        # update neighbors
        for x,y in news:
            self.skin[x][y] = True
            
        # make sure we're not making fake skin
        for x,y in (news + skins):
            if not self.is_skin((x,y)):
                self.skin[x][y] = False
                self.snake[x][y] = True
                
        # get potential next steps
        # can move to any skin bordering a snake
        next_steps = []
        for x in xrange(self.R):
            for y in xrange(self.C):
                if self.skin[x][y]:
                    directs = self.direct_neighbors((x,y))
                    touch_snake = [self.snake[a][b] for a,b in directs]
                    if reduce(lambda a,b:a or b,touch_snake):
                        next_steps.append((x,y))
            
        return next_steps
        
    def print_snake(self):
        s = ''
        clicked = False
        for i in xrange(self.R):
            for j in xrange(self.C):
                if not clicked and self.snake[i][j]:
                    s += 'c'
                    clicked = True
                elif self.skin[i][j] or self.snake[i][j]:
                    s += '.'
                else:
                    s += '*'
            if i < self.R - 1:
                s += '\n'
        return s

import heapq

def solve(R,C,M):
    # number of non mine squares
    N = R*C - M
    
    # corner cases
    if N == 1:
        s = Snake(R,C)
        s.snake[0][0] = True
        s.size = 1
        return s
    
    # starter snake
    start = Snake(R,C)
    init_points = []
    for i in xrange((R+1)/2):
        init_points.append((i,0))
    for j in xrange(1,(C+1)/2):
        init_points.append((0,j))

    snake_heap = []
    for point in init_points:
        heapq.heappush(snake_heap,(-start.size,start,point))
    
    while len(snake_heap) > 0:
        _, current, next_point = heapq.heappop(snake_heap)
        if current.size == N:
            return current
        updates = current.update(next_point)
        if current.size == N:
            return current
        elif current.size < N:
            # add back to heap
            for p in updates:
                next_snake = current.copy()
                heapq.heappush(snake_heap,(-next_snake.size,next_snake,p))
    
    return None

for i in xrange(trials):
    R,C,M = [int(f) for f in infile.readline().split()]
    
    winner = solve(R,C,M)

    if winner == None:
        solvestring = 'Impossible'
    else:
        solvestring = winner.print_snake()

    s = "Case #%d: \n%s\n" % (i+1,solvestring)
    outfile.write(s)
    print s
    
infile.close()
outfile.close()
