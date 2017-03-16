#!/usr/local/bin/python3
# Codejam iD 6224486
# Run with parameter
# -s for small input
# -l for large input


from GCJ import GCJ


def parse(infile):
    L, X = GCJ.readints(infile)
    s = GCJ.readstr(infile)
    return L, X, s

def solve(data):
    def sgn(a):
      return (a > 0) - (a < 0)
    i = 2
    j = 3
    k = 4
    L, X, s = data
    translate = {'i':i,'j':j,'k':k}
    digits = [ translate[ch] for ch in s ]

    count = { i: s.count('i'), j: s.count('j'), k: s.count('k') }
    div = 0
    for a in [i,j,k]:
      if count[a] > 0:
        div += 1
    if div <= 1:
      return 'NO'

    def multiply(a,b):
      sign = sgn(a*b)
      aa = abs(a)
      bb = abs(b)
      if aa == 1 or bb == 1:
        return aa*bb*sign
      elif aa == i:
        return [i,-1,k,-j][bb-1]*sign
      elif aa == j:
        return [j,-k,-1,i][bb-1]*sign
      elif aa == k:
        return [k,j,-i,-1][bb-1]*sign

    front, middle, back = 0, 0, 0
    res = 1
    index = 0
    limit = 0
    remLs = X
    for front in range(L*X):
      res = multiply(res, digits[index] )
      if res == i:
        break
      index += 1
      if index >= L:
        index = 0
        remLs -= 1
      limit+=1
      if limit > 1000:
        return 'NO'


    if res != i:
      return 'NO'

    res = 1
    index = L-1
    limit = 0
    for back in range(L*X-1,front+1,-1):
      res = multiply( digits[index], res )
      if res == k:
        break
      index -= 1
      if index < 0:
        index = L-1
        remLs -= 1
      limit += 1
      if limit > 1000:
        return 'NO'

    if res != k:
      return 'NO'

    res = 1
    index = (front+1)%L
    if remLs <= 2:
      for middle in range(front+1, back):
        res = multiply(res, digits[index] )
        index += 1
        if index >= L:
          index = 0
      if res == j:
        return 'YES'
      else:
        return 'NO'
    else:
      start, end = 1, 1
      remLs -= 2
      if (front%L) < L-1:
        for a in range((front+1)%L, L):
          start = multiply(start, digits[a] )
      end = 1
      if (back%L) > 0:
        for a in range((back-1)%L, -1, -1):
          end = multiply(digits[a], end)

      l = 1
      for a in range(L):
        l = multiply(l,digits[a])
      middle = 1
      for a in range(0,remLs%4):
        middle = multiply(middle,l)

      res = multiply(start, middle)
      res = multiply(res, end)
      if res == j:
        return 'YES'
      else:
        return 'NO'

if __name__ == "__main__":
  GCJ('C', solve, parse, None).run()

