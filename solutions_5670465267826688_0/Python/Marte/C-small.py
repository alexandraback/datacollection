Table = [[(1, 0), (1, 1), (1, 2), (1, 3)],
         [(1, 1), (-1, 0), (1, 3), (-1, 2)],
         [(1, 2), (-1, 3), (-1, 0), (1, 1)],
         [(1, 3), (1, 2), (-1, 1), (-1, 0)]]
InvTable = [[(1, 0), (-1, 1), (-1, 2), (-1, 3)],
            [(1, 1), (1, 0), (-1, 3), (1, 2)],
            [(1, 2), (1, 3), (1, 0), (-1, 1)],
            [(1, 3), (-1, 2), (1, 1), (1, 0)]]

Index = "1ijk"

def mul(a, b):
  x = a[0] * b[0]
  val = Table[a[1]][b[1]]
  return x*val[0], val[1]

def div(a, b):
  x = a[0] * b[0]
  val = InvTable[a[1]][b[1]]
  return x*val[0], val[1]

for cas in xrange(1, input()+1):
  print "Case #%d:" % cas,
  L, X = map(int, raw_input().split(" "))
  s = raw_input()
  assert len(s) == L
  s *= X
  vals = []
  curr = (1, 0)
  for c in s:
    curr = mul(curr, (1, Index.index(c)))
    vals.append(curr)
  def can():
    for i in xrange(len(vals)):
      for j in xrange(i+1, len(vals)-1):
        if vals[i] == (1, 1) and \
           mul(div((1, 0), vals[i]), vals[j]) == (1, 2) and \
           div(vals[-1], vals[j]) == (1, 3):
          return True
  print ("YES" if can() else "NO")
