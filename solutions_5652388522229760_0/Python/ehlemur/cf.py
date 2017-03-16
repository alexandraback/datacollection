n = int(input())

for i in range(n):
  print 'Case #{}:'.format(i+1),
  a = int(input())

  if i == 0:
    print 'INSOMNIA'
    continue

  seen = set()
  j = 0
  while True:
    j += 1
    seen = seen.union(set(str(a*j)))
    if len(seen) == 10:
      print a*j
      break
