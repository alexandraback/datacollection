import random

def get1(x):
  return chr(ord('A') + x)

def get2(x, y):
  return get1(x) + get1(y)

cases = int(raw_input())

t = 1
while True:
  print 'Case #%d:' % t,
  t += 1

  b, m = [int(x) for x in raw_input().split()]
  if m > 2 ** (b - 2):
    print 'IMPOSSIBLE'
  else:
    print 'POSSIBLE'
    for i in xrange(0, b):
      values = []
      for j in xrange(0, b):
        if (j <= i):
          values.append('0')
        else:
          if (i == 0):
            if (j == (b-1)):
              if (m == (2 ** (b-2))):
                  values.append('1')
              else:
                  values.append('0')
            else:
              count = 2 ** (b - 2 - j)
              foo = m
              if (m == (2 ** (b-2))):
                foo = m - 1

              if foo & count:
                  values.append('1')
              else:
                  values.append('0')
          else:
            values.append('1')
      print ''.join(values)


  if t == cases + 1:
    break
