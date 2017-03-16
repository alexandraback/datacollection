f = open("C-small-attempt2.in","rt")
O = open("C.out", "wt")

def sol():
  A,B,C,K = map(int,f.readline().split(' '))
  R = []
  P = 0       
  c = 1
  U = {}
  V = {}
  for a in range(1,A+1):
    for b in range(1,B+1):
        i = 0
        while i < min(C,K):
          key = (a,c)
          key2 = (b,c)
          if key not in U:
            U[key] = 0
          if key2 not in V:
            V[key2] = 0
          if U[key]<K and V[key2]<K:
            U[key] += 1
            V[key2] += 1
            R += ["%d %d %d" %(a,b,c)]
            P += 1
            i += 1
          c = c%C + 1
  return '%d\n' %P + "\n".join(R)

T = int(f.readline())

for t in range(T):
    S = "Case #%d: " %(t+1)                           
    S += sol()
    O.write(S)
    O.write("\n")
    print S