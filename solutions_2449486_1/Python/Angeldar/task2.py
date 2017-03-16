# CodeJam 2013
# Task A

def solve():
  f = open('in')
  out = open('out','w')
  T = int(f.readline())
  for n1 in range(T):
    line = f.readline()
    N, M = [int(t) for t in (line).split()]
    arr = []
    for n2 in range(N):
      arr.append([int(t) for t in f.readline().split()])
    arrLR = [[0 for t in range(M)] for k in range(N)]
    arrRL = [[0 for t in range(M)] for k in range(N)]
    arrTB = [[0 for t in range(M)] for k in range(N)]
    arrBT  = [[0 for t in range(M)] for k in range(N)]
    for i in range(N):
      arrLR[i][0] = arr[i][0]
      arrRL[i][M-1] = arr[i][M-1]
    for i in range(M):
      arrTB[0][i] = arr[0][i]
      arrBT[N-1][i] = arr[N-1][i]

    for i in range(N):
      for j in range(1,M):
        arrLR[i][j] = max(arrLR[i][j-1],arr[i][j])
        arrRL[i][M-1-j] = max(arrRL[i][M-1-j+1],arr[i][M-1-j])

    for i in range(1,N):
      for j in range(M):
        arrTB[i][j] = max(arrTB[i-1][j],arr[i][j])
        arrBT[N-1-i][j] = max(arrBT[N-1-i+1][j], arr[N-1-i][j])
        
    ans = True
    for i in range(N):
      if not ans: break
      for j in range(M):
        if (arrLR[i][j] > arr[i][j] or arrRL[i][j] > arr[i][j]) and (arrBT[i][j] > arr[i][j] or arrTB[i][j] > arr[i][j]):
          ans = False
          break
    if ans: res="YES"
    else: res="NO"
    out.write(("Case #%d: " % (n1+1)) +res+'\n')
  f.close()
  out.close()


print 'Start'
solve()
print 'Done'