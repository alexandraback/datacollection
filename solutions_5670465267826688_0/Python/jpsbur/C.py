#!/usr/bin/python3

def mul (x, y):
  xa, xb = x
  ya, yb = y
  if xa == '1':
    return ya, xb * yb
  elif ya == '1':
    return xa, xb * yb
  elif xa == 'i':
    if ya == 'i':
      return '1', -xb * yb
    elif ya == 'j':
      return 'k', xb * yb
    elif ya == 'k':
      return 'j', -xb * yb
  elif xa == 'j':
    if ya == 'i':
      return 'k', -xb * yb
    elif ya == 'j':
      return '1', -xb * yb
    elif ya == 'k':
      return 'i', xb * yb
  elif xa == 'k':
    if ya == 'i':
      return 'j', xb * yb
    elif ya == 'j':
      return 'i', -xb * yb
    elif ya == 'k':
      return '1', -xb * yb
  return False

def pw (x, a):
  if a == 0:
    return '1', 1
  if a == 1:
    return x
  t = pw (x, a // 2)
  t = mul (t, t)
  if a % 2 == 1:
    return mul (x, t)
  return t

def solve ():
  L, X = [int (x) for x in input ().split ()]
  s = input ()
  ss = s[::-1]
  zs = '1', 1
  for a in s:
    zs = mul (zs, (a, 1))
  #print (str (zs))
  z = pw (zs, X)
  #print (str (z))
  if z != ('1', -1):
    return 'NO'

  al = L * X
  t = '1', 1
  i = 0
  for a in s:
    i += 1
    t = mul (t, (a, 1))
    #print ('-> ' + str (t))
    t1 = t
    for x in range (5):
      #print ('-> ' + str (t1))
      if t1 == ('i', 1):
        al = min (al, x * L + i)
      t1 = mul (zs, t1)

  ar = L * X
  t = '1', 1
  i = 0
  for a in ss:
    i += 1
    t = mul ((a, 1), t)
    t1 = t
    for x in range (5):
      if t1 == ('k', 1):
        ar = min (ar, x * L + i)
      t1 = mul (t1, zs)

  #print (al, ar)

  if al + ar < L * X:
    return 'YES'
  return 'NO'

T = int (input ())
for t in range (T):
  print ('Case #' + str (t + 1) + ': ' + str (solve ()))
