import sys
fin = open('in.txt', 'r')
fout = open('out1.txt', 'w')
n = int(fin.readline())
for T in range(0, n):
  ret = True
  array = [int(x) for x in  fin.readline().split()]
  m = int(array[0])
  s = int(array[1])
  board = []
  for k in range(0, m):
    array = [int(x) for x in  fin.readline().split()]
    board.append(array)
  for k in range(0,m):
    for j in range(0,s):
      t = int(board[k][j])
      f1 = True;
      f2 = True;
      for z in range(0,m):
        if t < int(board[z][j]):
          f1 = False
      for z in range(0,s):
        if t < int(board[k][z]):
          f2 = False
      ret = ret and (f1 or f2)
  fout.write("Case #" + str(T + 1) + ": ")
  if ret:
    fout.write("YES\n")
  else:
    fout.write("NO\n");