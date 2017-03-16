import sys

def getChildren((x, y)):
   return [(x-1, y-1), (x+1, y-1)]

class Board(object):
   def __init__(self, oldBoard=None):
      if oldBoard is None:
         self.board = set()
         self.height = -2
      else:
         self.board = set(oldBoard.board)
         self.height = oldBoard.height

   def placeDiamond(self, x, y):
      assert (x, y) not in self.board
      assert (x + y) % 2 == 0
      if y > 0:
         assert (x+1, y-1) in self.board
         assert (x-1, y-1) in self.board

      if x == 0:
         assert y > self.height
         self.height = y

      self.board.add( (x, y) )
      assert self.isLegal()#<<<

   def findNextLandings(self, potLanding=None):
      if potLanding is None:
         potLanding = ( 0, self.height + 2)

      #print potLanding#<<<
      #print self.board#<<<
      assert potLanding[1] - 2 < 0 or ( potLanding[0], potLanding[1] - 2 ) in self.board

      children = getChildren(potLanding)
      if all(child in self.board for child in children):
         # if both children are on, we're done
         return [ potLanding ]
      elif children[1] in self.board:
         # go left
         landing1 = self.findNextLandings(children[0])
         assert len(landing1) == 1
         landing1 = landing1[0]
         return [ landing1 ]
      elif children[0] in self.board:
         # go right
         landing2 = self.findNextLandings(children[1])
         assert len(landing2) == 1
         landing2 = landing2[0]
         return [ landing2 ]
      else:
         if potLanding[1] == 0:
            # we've hit the ground!
            return [ potLanding ]
         landing1 = self.findNextLandings(children[0])
         assert len(landing1) == 1
         landing1 = landing1[0]

         landing2 = self.findNextLandings(children[1])
         assert len(landing2) == 1
         landing2 = landing2[0]

         return [ landing1, landing2 ]

   def isLegal(self):
      for d in self.board:
         if d[1] == 0:
            pass
         else:
            if not all(child in self.board for child in getChildren(d)):
               return False

      return True

def generateAllBoards(N, board=None):
   if board is None:
      board = Board()
   if N == 0:
      return [ board ]
   
   boards = []
   landings = board.findNextLandings()
   for landing in landings:
      newBoard = Board(board)
      newBoard.placeDiamond(*landing)
      newBoards = generateAllBoards(N-1, newBoard)
      boards += newBoards

   return boards

def prDiamond(N, x, y):
   assert (x+y) % 2 == 0
   
   boards = generateAllBoards(N)
   
   onCount = 0
   for board in boards:
      if (x, y) in board.board:
         onCount += 1

   return 1.0*onCount / len(boards)

def main():
   lines = open(sys.argv[1], 'r').read().split("\n")
   testCases = lines.pop(0)
   testCases = int(testCases)

   for i in range(testCases):
      N, x, y = [ int(n) for n in lines.pop(0).split() ]
      status = prDiamond(N, x, y)
      print "Case #%s: %s" % ( i+1, status )

if __name__ == "__main__":
   main()
