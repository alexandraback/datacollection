def add_digits(s, n):
  if n == 0: s.add(0)
  while n > 0:
    s.add(n%10)
    n /= 10

_T = int(raw_input())
for _t in range(1, _T+1):

  N = int(raw_input())

  if N == 0:
    res = 'INSOMNIA'
  else:
    s = set()
    n = N
    add_digits(s, n)
    while len(s) < 10:
      n += N
      add_digits(s, n)
    res = n

  print 'Case #{}: {}'.format(_t, res)
