import sys
import pprint

def analyzeBoard(board):
   height, width = len(board), len(board[0])
   ogLawn = []
   for i in range(height):
      ogLawn.append([100]*width)

   for i, row in enumerate(board):
      cutHeight = max(row)
      ogLawn[i] = [ min(cutHeight, curHeight) for curHeight in ogLawn[i] ]

   for j, column in enumerate(zip(*board)):
      cutHeight = max(column)
      for row in ogLawn:
         row[j] = min(cutHeight, row[j])

   if ogLawn == board:
      return "YES"
   else:
      return "NO"


def main():
   lines = open(sys.argv[1], 'r').read().split("\n")
   testCases = lines.pop(0)
   testCases = int(testCases)

   for i in range(testCases):
      n, m = lines.pop(0).split(" ")
      n = int(n)
      m = int(m)
      board = []
      for nthRow in range(n):
         row = [ int(height) for height in lines.pop(0).split(" ") ]
         assert len(row) == m
         board.append(row)
      status = analyzeBoard(board)
      print "Case #%s: %s" % ( i+1, status )

if __name__ == "__main__":
   main()
