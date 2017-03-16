import sys
sys.stdin = open("B-small-attempt1.in")
sys.stdout = open("0Bout.txt","w")
T = int(input())
R,C=0,0
def check(board):
   global R,C
   maxRow={}
   maxCol={}
   for r in range(R):
      maxRow[r]=max(board[r])
   for c in range(C):
      temp=[]
      for r in range(R):
         temp.append(board[r][c])
      maxCol[c]=max(temp)
   #print (maxRow,maxCol)
   for r in range(R):
      for c in range(C):
         if board[r][c]<maxRow[r] and board[r][c]<maxCol[c]:
            return "NO"
   return "YES"
for _ in range(T):
   board=[]
   R,C=[int(x) for x in input().split(' ')]
   #print(R,C)
   for line in range(R):
      board.append([int(x) for x in input().split(' ')])
   print("Case #"+str(_+1)+": "+check(board))
   #for i in range(R):
      #print (board[i])
sys.stdout.close()
