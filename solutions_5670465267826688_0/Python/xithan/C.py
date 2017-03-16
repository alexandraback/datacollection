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
    i = 2
    j = 3
    k = 4
    L, X, s = data
    translate = {'i':i,'j':j,'k':k}
    digits = [ translate[ch] for ch in s ]

    def multiply(a,b):
      if a*b > 0:
        sign = 1
      else:
        sign = -1
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
    for front in range(L*X):
      res = multiply(res, digits[index] )
      index += 1
      if index >= L:
        index = 0
      if res == i:
        break
    if res != i:
      return 'NO'

    res = 1
    index = L-1
    for back in range(L*X-1,front+1,-1):
      res = multiply( digits[index], res )
      index -= 1
      if index < 0:
        index = L-1
      if res == k:
        break
    if res != k:
      return 'NO'

    res = 1
    index = (front+1)%L
    for middle in range(front+1, back):
      res = multiply(res, digits[index] )
      index += 1
      if index >= L:
        index = 0

    if res == j:
      return 'YES'
    else:
      return 'NO'

if __name__ == "__main__":
  GCJ('C', solve, parse, None).run()

