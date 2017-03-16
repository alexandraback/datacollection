T = input()

for _ in range(T):
  print 'Case #{}:'.format(_+1),
  s = raw_input()
  t = ''
  for c in s:
    if len(t) == 0 or c != t[-1]:
      t += c

  print len(t) - (t[-1] == '+')
    
