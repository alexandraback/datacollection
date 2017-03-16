#!/usr/bin/python

import sys

neighbors = [ (-1,-1),(0,-1),(1,-1),(-1,0),    (1,0),(-1,1),(0,1),(1,1)]

EMPTY = 0
MINE  = 1
CLICK = 2

def forEachNeighbor(field,rpos,cpos,callme):
   retval = []
   for relpos in neighbors:
      nrpos = rpos+relpos[0]
      ncpos = cpos+relpos[1]
      #ignore outside of play area
      if nrpos < 0 or nrpos >= len(field):
         continue
      if ncpos < 0 or ncpos >= len(field[nrpos]):
         continue
      #print str(callme)+str([rpos,cpos,nrpos,ncpos])
      retval.append(callme(field,nrpos,ncpos))
   #print str(callme) + str(retval)
   return retval

def isMine(field,rpos,cpos):
   return field[rpos][cpos] == MINE

def isClear(field,rpos,cpos):
   return isClearWithPos(field,rpos,cpos)[0]

def isClearWithPos(field,rpos,cpos):
   if field[rpos][cpos] == MINE: #Mines are not clear
      return (False,(rpos,cpos))

   ms = forEachNeighbor(field,rpos,cpos,isMine)
   for m in ms:
      if m:
         return (False,(rpos,cpos))
   return (True,(rpos,cpos))
   

def hasClearNeighbor(field,rpos,cpos):
   if field[rpos][cpos] == MINE: #we don't care if mines have clear neighbors
      return True

   cs = forEachNeighbor(field,rpos,cpos,isClear)
   for c in cs:
      if c:
         return True
   return False

def isClearAreaContiguous(field):
   R = len(field)
   C = len(field[0])
   clearpts = set()
   tosearch = set()
   #find first clear point
   for pos in range(0,R*C):
      rpos = pos % R
      cpos = pos // R
      if isClear(field,rpos,cpos):
         clearpts.add((rpos,cpos))
         tosearch.add((rpos,cpos))
         break
   
   while len(tosearch) > 0:
      rpos,cpos = tosearch.pop()
      cs = forEachNeighbor(field,rpos,cpos,isClearWithPos)
      for c in cs:
         if c[0] and c[1] not in clearpts:
            clearpts.add(c[1])
            tosearch.add(c[1])
   
   for pos in range(0,R*C):
      rpos = pos % R
      cpos = pos // R
      if isClear(field,rpos,cpos) and (rpos,cpos) not in clearpts:
         return False
   return True

def AddMines(field,M,start):
   #Try to add M mines after start
   if M==0:
      return field
   
   R = len(field)
   C = len(field[0])
   for pos in range(start,R*C):
      rpos = pos % R
      cpos = pos // R
      if field[rpos][cpos] != EMPTY:
         continue
         
      #put a mine here
      field[rpos][cpos] = MINE
      
      ncn = forEachNeighbor(field,rpos,cpos,hasClearNeighbor) #all neighbors must have a clear neighbor
      if not reduce(lambda a,b: a and b,ncn):
         field[rpos][cpos] = EMPTY
         continue
      
      tmpresult = AddMines(field,M-1,pos+1)
      if tmpresult and isClearAreaContiguous(field):
         return tmpresult
      
      #remove the mine and try other positions
      field[rpos][cpos] = EMPTY
      
   return None
      


def Solve(R,C,M,bottomFree,rightFree):
   #for every permutation of position of mines in area
   field = [ [ EMPTY for x in range(0,C) ] for x in range(0,R) ]
   if not bottomFree:
      field.append([MINE,] * C)
   if not rightFree:
      for row in field:
         row.append(MINE)      
   
   solution = AddMines(field,M,0)

   if solution:
      #It is possible, now find a good tile
      goodsolution = None
      
      for ridx in range(0,len(solution)):
         for cidx in range(0,len(solution[ridx])):
            if solution[ridx][cidx] != MINE: #found a non-mine tile (solution if no clear tiles)
               goodsolution = (ridx,cidx)
            if isClear(solution,ridx,cidx): #found a clear tile
               solution[ridx][cidx]=CLICK
               return solution
      if goodsolution and (R*C-M) == 1: #only use non-clear if it is the only one
         solution[goodsolution[0]][goodsolution[1]]=CLICK
         return solution
   else:
      return None

def processCase(case):
   R,C,M = [int(x) for x in sys.stdin.readline().split()]
   print "Case #%d:" % (case+1,)

   
   minRows = (R*C-M+C-1)//C #ceil( (R*C-M)/C)
   for Reff in range(minRows,R+1): #rows not completely filled with mines
      Meff = M-C*(R-Reff)
      Ceff = (Reff*C-Meff+Reff-1)//Reff #columns not completely filled with mines
      Mfree = Meff-Reff*(C-Ceff)
      
      solution = Solve(Reff,Ceff,Mfree,Reff==R,C==Ceff)
      if solution:
         #add rows and columns full of mines
         #add columns
         for row in solution:
            row.extend([ MINE,]*(C-len(row)))
         #add rows
         solution.extend([ [MINE,]*C,]*(R-len(solution)))
         tilemap = { EMPTY : '.', MINE : '*', CLICK : 'c' }
         nmines = 0
         assert(len(solution)==R)
         for row in solution:
            line = ''.join([tilemap[x] for x in row])
            nmines += line.count(tilemap[MINE])
            assert(len(line)==C)
            print line
         assert nmines == M
         return
   print "Impossible"# + str((R,C,M))
        


num = int(sys.stdin.readline())

for case in range(0,num):
    processCase(case)
