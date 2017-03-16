f = open("B-small-attempt0.in","rt")
O = open("B.out", "wt")

def sol():
  B,M = map(int, f.readline().split(' '))
  if M>2**(B-2):
    return 'IMPOSSIBLE\n'
  D = []
  for i in range(B):
    D += [[]]
    for j in range(B):
      if j==B-1:
        if M==2**(B-2):
          D[-1] += [int(i<j)]
        elif i==0:
          D[-1] += [0]
        else:
          D[-1] += [int(M&2**(i-1)>0)]
      else:      
        D[-1] += [int(i<j and j<B-1)]
  R = ''
  for l in D:
    for c in l:
      R += `c`
    R +='\n'   
  return 'POSSIBLE\n'+R

T = int(f.readline())

for t in range(T):
    S = "Case #%d: " %(t+1)                           
    S += sol()
    O.write(S)
    print S