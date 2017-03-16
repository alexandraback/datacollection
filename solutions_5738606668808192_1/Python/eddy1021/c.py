import sys
N = 1048576
p, f = [True] * N, [-1] * N
p[0] = p[1] = False
pr = []
for i in range( 2 , N ):
  if p[i] == False: continue
  pr.append( i )
  for j in range( N // i , i - 1 , -1 ):
    if i*j < N:
      p[i*j], f[i*j] = False, i
def isp( x ):
  if x < N:
    if p[x]: return -1
    return f[x]
  else:
    for i in pr:
      if x % i == 0:
        return i
    return -1
T = raw_input()
nn, J = raw_input().split()
nn, J = int(nn), int(J)
bt = [0] * nn
bt[0] = bt[nn-1] = 1
print( "Case #1:" )
def cal( bs ):
  vl, a = 0, 1
  for i in range( nn ):
    vl += a * bt[ i ]
    a *= bs
  return isp( vl ), vl
def test():
  pos, ans = [], 0
  for i in range(2,11):
    p, a = cal(i)
    if p == -1: return
    ans = a
    pos.append( p )
  pos = [ans] + pos
  print( ' '.join( map(str,pos) ) )
  global J
  J -= 1
  if J == 0:
    sys.exit()
for ii in range( 2 ** ( nn - 2 ) ):
  for jj in range( nn - 2 ):
    if ( ii >> jj ) & 1: bt[ jj + 1 ] = 1
    else: bt[ jj + 1 ] = 0
  test();
