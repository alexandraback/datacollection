def DeceitfulWar(A, B):
  result = 0

  C = list(A)
  D = list(B)
  n = len(C)

  for strategy in xrange(0, n+1):
    correct = True
    for i in xrange(len(C)):
      if C[i] < D[i]:
        correct = False; break
    if correct:
      return n-strategy

    C.pop(0)
    D.pop(-1)    

def War(A, B):
  result = 0
  
  C = list(A)
  D = list(B)

  for elem in C:
    if D[-1] < elem: result += 1; D.pop(0)
    else:
      for i in xrange(len(D)):
        if D[i] > elem:
          D.pop(i); break
  return result  

def Solve():
  n = int(raw_input())
  A = map(float, raw_input().split())
  B = map(float, raw_input().split())
  A.sort(); B.sort()

  print "%d %d" % (DeceitfulWar(A, B), War(A, B))

if __name__ == '__main__':
  q = int(raw_input())
  for i in xrange(1, q+1):
    print "Case #%d:" % (i),
    Solve()
