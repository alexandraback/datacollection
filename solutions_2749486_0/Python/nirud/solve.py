'''
Created on May 12, 2013

@author: nils
'''

def solve(posistions, visited, goal):
    
    while posistions:
    
        pos = posistions[0][0]
        walk = posistions[0][1]
        
#        print(pos, walk)
         
        n = len(walk) + 1
        if pos[0] == goal[0] and pos[1] == goal[1]:
            return walk
            
        new_positions = posistions[1:]
        
        north = (pos[0], pos[1] + n)
        south = (pos[0], pos[1] - n)
        east = (pos[0]+ n, pos[1])
        west = (pos[0]-n, pos[1])
        
        next_moves = []
        
        if not north in visited:
            next_moves.append((north, walk+"N"))
            visited.add(north)
        if not south in visited:
            next_moves.append((south, walk+"S"))
            visited.add(south)
        if not east in visited:
            next_moves.append((east, walk+"E"))
            visited.add(east)
            
        if not west in visited:
            next_moves.append((west, walk+"W"))
            visited.add(west)
        
        def k(x):
            posx = x[0]
            dx = goal[0] - posx[0]
            dy = goal[1] - posx[1]
            return dx *dx + dy*dy
        
        next_moves.sort(key= k)
        
        posistions = new_positions + next_moves
        
    return ""
    
    
    
    
    
    