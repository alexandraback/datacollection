# CodeJam 2013
# Task A

def isWin(arr, c):
  for i in range(4):
    k1, k2 = 0, 0
    for j in range(4):
      if arr[i][j]==c or arr[i][j]=='T': k1+=1
      if arr[j][i]==c or arr[j][i]=='T': k2+=1
    if k1==4 or k2==4:
      return True
  k1, k2 = 0, 0
  for i in range(4):
    if arr[i][i]==c or arr[i][i]=='T': k1+=1
    if arr[i][3-i]==c or arr[i][3-i]=='T': k2+=1
  if k1==4 or k2==4:
    return True
  return False

def isDraw(arr):
  for i in range(4):
    for j in range(4):
      if arr[i][j]=='.':
        return False
  return True

def solve():
  f = open('in')
  out = open('out','w')
  T = int(f.readline())
  for i in range(T):
    arr = []
    for j in range(4):
      arr.append(list(f.readline()))
    ans = ''
    if isWin(arr,'X'): ans = 'X won'
    elif isWin(arr,'O'): ans = 'O won'
    elif isDraw(arr): ans = 'Draw'
    else: ans = 'Game has not completed'
    out.write(("Case #%d: " % (i+1)) +ans+'\n')
    f.readline()
  f.close()
  out.close()

print 'Start'
solve()
print 'Done'