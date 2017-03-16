from sys import stdin

def mult(a, b):
  neg = False
  if a[0] == '-':
    neg = not neg
    a = a[1:]
  if b[0] == '-':
    neg = not neg
    b = b[1:]
  if a == '1':
    ret = b
  elif b == '1':
    ret = a
  elif a == b:
    ret = '1'
    neg = not neg
  elif a == 'i' and b == 'j':
    ret = 'k'
  elif a == 'i' and b == 'k':
    ret = 'j'
    neg = not neg
  elif a == 'j' and b == 'i':
    ret = 'k'
    neg = not neg
  elif a == 'j' and b == 'k':
    ret = 'i'
  elif a == 'k' and b =='i':
    ret = 'j'
  elif a == 'k' and b =='j':
    ret = 'i'
    neg = not neg
  if neg:
    return '-' + ret
  return ret

def ppow(a, k):
  if k % 4 == 0:
    return 1
  elif k % 4 == 1:
    return a
  elif k % 4 == 2:
    return mult(a, a)
  return mult(a, mult(a, a))

T = int(stdin.readline())
for _ in range(T):
  L, X = map(int, stdin.readline().split())
  S = stdin.readline().strip()
  prod = reduce(mult, S, '1')
  # print 'prod', prod
  if ppow(prod, X) != '-1':
    ans = "NO"
  else:
    ml = L * X
    acc = '1'
    for i in range(L):
      if acc == 'i':
        ml = min(ml, i)
      elif mult(prod, acc) == 'i':
        ml = min(ml, i + L)
      elif mult('-1', acc) == 'i':
        ml = min(ml, i + 2*L)
      elif mult(mult('-1', prod), acc) == 'i':
        ml = min(ml, i + 3*L)
      acc = mult(acc, S[i])
    # print 'ml', ml

    mr = L * X
    acc = '1'
    for i in range(L-1, -1, -1):
      if acc == 'k':
        mr = min(mr, (L-1-i))
      elif mult(acc, prod) == 'k':
        mr = min(mr, (L-1-i) + L)
      elif mult(acc, '-1') == 'k':
        mr = min(mr, (L-1-i) + 2*L)
      elif mult(acc, mult('-1', prod)) == 'k':
        mr = min(mr, (L-1-i) + 3*L)
      acc = mult(S[i], acc)
    # print 'mr', mr

    ans = 'YES' if ml + mr < L*X else 'NO'

  print 'Case #{}: {}'.format(_+1, ans)
