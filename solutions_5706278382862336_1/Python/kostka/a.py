from fractions import gcd

ttt = int(input())

def popcnt(a):
  wyn = 0
  while a != 0:
    if a % 2:
      wyn += 1
    a //= 2
  return wyn
  
def wieksze(A,C):
  (a,b) = A
  (c,d) = C
  q = b*d/gcd(b,d)
  a *= q/b
  c *= q/d
  return a>=c
  

for tti in range(ttt):
  print("Case #%d: " % (tti+1), end="")
  buf = input().split("/")
  p = int(buf[0])
  q = int(buf[1])
  d = gcd(p,q)
  p //= d
  q //= d
  if popcnt(q) != 1:
    print("Impossible")
    continue
  czy = False
  for i in range(1,42):
    if wieksze((p,q),(1,2**i)):
      czy = True
      print(i)
      break
  if czy == False:
    print("Impossible")