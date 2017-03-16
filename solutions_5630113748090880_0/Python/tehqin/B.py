

T = int(raw_input())
for tc in range(1, T+1):

   N = int(raw_input())
   rows = []
   for i in range(2*N-1):
      rows.append(map(int, raw_input().split()))
   rows.sort()

   res = []
   grid = [[-1]*N for i in range(N)]

   def isValid(x, y, v1, v2):
      if v1 == -1:
         return True
      if x == y:
         return v1 == v2
      if x < y:
         return v1 < v2
      return v2 < v1

   def checkRow(r, vec):
      for c in range(N):
         for rr in range(N):
            if not isValid(rr, r, grid[rr][c], vec[c]):
               return False
      return True
   def markRow(r, vec):
      for c in range(N):
         grid[r][c] = vec[c]

   def checkCol(c, vec):
      for r in range(N):
         for cc in range(N):
            if not isValid(cc, c, grid[r][cc], vec[r]):
               return False
      return True
   def markCol(c, vec):
      for r in range(N):
         grid[r][c] = vec[r]

   loCol = 0
   loRow = 0
   hiCol = N-1
   hiRow = N-1
   
   p1 = 0
   p2 = len(rows)-1
   count = 0
   while count < len(rows)-2:
      if rows[p1][0] == rows[p1+1][0]:
         if checkRow(loRow, rows[p1]) and checkCol(loCol, rows[p1+1]):
            markRow(loRow, rows[p1])
            markCol(loCol, rows[p1+1])
         else:
            markCol(loCol, rows[p1])
            markRow(loRow, rows[p1+1])

         loRow += 1
         loCol += 1
         p1 += 2
      else:
         if checkRow(hiRow, rows[p2]) and checkCol(hiCol, rows[p2-1]):
            markRow(hiRow, rows[p2])
            markCol(hiCol, rows[p2-1])
         else:
            markCol(hiCol, rows[p2])
            markRow(hiRow, rows[p2-1])
         
         hiRow -= 1
         hiCol -= 1
         p2 -= 2
      count += 2

   if checkRow(loRow, rows[p1]):
      markRow(loRow, rows[p1])
      res = [grid[x][loCol] for x in range(N)]
   else:
      markCol(loCol, rows[p1])
      res = [grid[loRow][x] for x in range(N)]

   print 'Case #%d: %s' % (tc, ' '.join(map(str,res)))
