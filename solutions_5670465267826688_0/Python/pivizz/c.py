import sys

def quat(c):
  d = {'i': 2, 'j': 3, 'k': 5}
  return d[c]

dmult = {
  1: {1: 1, 2: 2, 3: 3, 5: 5},
  2: {1: 2, 2:-1, 3: 5, 5:-3},
  3: {1: 3, 2:-5, 3:-1, 5: 2},
  5: {1: 5, 2: 3, 3:-2, 5:-1},
}

def mult(q1, q2):
  s1 = 1 if q1 > 0 else -1
  s2 = 1 if q2 > 0 else -1
  q1 = s1*q1
  q2 = s2*q2
  return s1*s2*dmult[q1][q2]
  

def solve(L, X):
  p = 1
  l_cum_prod = []
  first_i = -1
  for i in range(4):
    for l in L:
      p = mult(p, l)
      l_cum_prod.append(p)
      if first_i < 0 and p == 2:
        first_i = len(l_cum_prod)

  #print(l_cum_prod)

  if first_i < 0: return 'NO'

  l_cum_prod_r = []
  first_k = -1
  rL = list(reversed(L))
  p = 1
  for i in range(4):
    for l in rL:
      p = mult(l, p)
      l_cum_prod_r.append(p)
      if first_k < 0 and p == 5:
        first_k = len(l_cum_prod_r)

  #print (l_cum_prod_r)

  if first_k < 0: return 'NO'

  l_full_prod = l_cum_prod[len(L)-1]
  full_prod = 1
  for i in range(X % 4):
    full_prod = mult(full_prod, l_full_prod)

  #print (full_prod)  

  if full_prod != -1: return 'NO'
  
  if first_i + first_k > len(L)*X: return 'NO'
  return 'YES'  

data = list(sys.stdin)[1:]
ncases = len(data) // 2

for caseIndex in range(ncases):
  X = int(data[2*caseIndex].rstrip().split(' ')[1])
  L = list(map(quat, data[2*caseIndex+1].rstrip()))
  answer = solve(L, X)
  print('Case #{0}: {1}'.format(caseIndex+1, answer))
