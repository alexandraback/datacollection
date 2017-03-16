import math

def myLog2(a):
  if a < 1:
    return 0
  k = 1
  cu = 2
  while cu <= a:
    cu *= 2
    k += 1
  return k

def quanjia(l, p, k, A, N):
  if p> k:
    return 0
  if A>l[p]:
    return quanjia(l, p+1, k, A+l[p], N)
  n = myLog2((l[p]-A)/float(A-1)+1)
  return n+quanjia(l, p+1, k, A+(2**n-1)*(A-1)+l[p], N)

def decide(l, A, N):
  minO = N
  for k in range(N):
    a =quanjia(l, 0, k, A, N)
    #print k, a
    if N-1-k+a < minO:
      minO =N-1-k+a
  return minO 
    

def solve():
  #f = open("in.txt", 'r')
  #f = open("A-small-attempt1.in", 'r')
  f = open("A-large.in", 'r')
  T = int(f.readline())
  for t in range(1, T+1):
    print "Case #%d:" %t,
    [A, N] = [int(k) for k in f.readline().split()]
    l = [int(k) for k in f.readline().split()]
    sl = sorted(l)
    if A is 1:
      print N
    else:
      print decide(sl, A, N)
    
solve()
