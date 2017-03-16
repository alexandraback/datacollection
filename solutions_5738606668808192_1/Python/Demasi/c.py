"""
LEN = 40000000
crivo = [True]*LEN

p = []
for i in xrange(4, LEN, 2):
  crivo[i] = False
for i in xrange(3, LEN, 2):
  if (crivo[i] is True):
    p.append(i)
    for j in xrange(i*i, LEN, 2*i):
      crivo[j] = False
"""

from primos import p

b = [0]*11
d = [0]*11

T = input()
for caso in xrange(1, T+1):
  N, J = [int(s) for s in raw_input().split(" ")]
  num = 2**(N-1)

  print("Case #{0}:".format(caso))

  for i in xrange(0, J):
    ok = False
    while(ok is False):
      num = num+1 
      if (num%2 != 0):
        ok = True
        for i in xrange(2, 11):
          if (ok is False):
            break
          temp = num
          base = 1
          b[i] = 0
          while(temp > 0):
            if (temp%2 != 0):
              b[i] += base
            base = base*i
            temp = temp/2
           
          primo = True
          for pj in p:
            if (pj*pj > b[i]) or (primo is False):
              break
            if (b[i]%pj == 0):
              primo = False
              d[i] = pj

          if (primo):
            ok = False

    t = num
    s = ""
    for j in xrange(0, N):
      if (t%2 == 0):
        s = s + "0"
      else:
        s = s + "1"
      t = t/2
    print s[::-1],
    for j in xrange(2, 11):
      print "{0}".format(d[j]),
    print
         
