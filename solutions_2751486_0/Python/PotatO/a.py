def a(string, n):
  n = int(n)
  cons = []
  counter = 0
  for i in range(len(string)):
    if string[i] in ['a', 'e', 'i', 'o', 'u']:
      if counter >= n:
        cons.append((i-counter, i-1))
      counter = 0
    else:
      if i == len(string)-1 and counter >= n-1:
        cons.append((i-counter, i))
      counter += 1
  print cons
  if len(cons) == 0:
    return 0
  result = 0
  for beg in range(len(string)):
    if beg <= cons[0][0]:
      result += len(string)-(cons[0][0]+n-1)
    elif beg > cons[-1][1]-n+1:
      return result
    else:
      for i in range(len(cons)):
        if beg >= cons[i][0] and (i == len(cons)-1 or beg < cons[i+1][0]):
          if cons[i][1]-beg+1 >= n:
            result += len(string)-(beg+n-1)
          else:
            result += len(string)-(cons[i+1][0]+n-1)
          break
  return result

f = open('a-small.in')
o = open('a-small.out', 'w')
n = int(f.readline())
for i in xrange(n):
  string, nn = f.readline().split()
  o.write('Case #%d: %d\n' % (i+1, a(string, nn)))
o.close()
f.close()
