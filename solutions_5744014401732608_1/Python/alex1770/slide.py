import sys

def thing(B,M):
  if M>(1<<(B-2)): print "IMPOSSIBLE";return
  print "POSSIBLE"
  if M==(1<<(B-2)): print "0"+"1"*(B-1)
  else:
    s="0"
    for i in range(B-2): s+="%d"%((M>>(B-3-i))&1)
    s+="0"
    print s
  for i in range(1,B-1): print "0"*(i+1)+"1"*(B-i-1)
  print "0"*B

T=int(sys.stdin.readline())
for case in range(1,T+1):
  [B,M]=[int(y) for y in sys.stdin.readline().strip().split()]
  print "Case #%d:"%case,;thing(B,M)
