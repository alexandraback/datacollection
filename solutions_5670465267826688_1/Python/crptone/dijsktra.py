#f = open('dijkstra.txt', 'r')
f = open('C-large.in', 'r')
g = open('dijkstra.out', 'w')
lines = int(f.readline())
count = 1

q = {
  '11': '1',
  '1i': 'i',
  '1j': 'j',
  '1k': 'k',
  'i1': 'i',
  'ii': '-1',
  'ij': 'k',
  'ik': '-j',
  'j1': 'j',
  'ji': '-k',
  'jj': '-1',
  'jk': 'i',
  'k1': 'k',
  'ki': 'j',
  'kj': '-i',
  'kk': '-1'
}

while count <= lines:
  n = int(f.readline().split()[1])
  s = f.readline().strip()
  i = False
  j = False
  k = False

  r = '1'
  p = 0
  #print(s*min(8,n))
  for c in (s*min(8,n)):      
    r = q[r + c]
    if r[0] == '-':
      r = r[1]
      p += 1
    if not i and r == 'i' and p % 2 == 0:
      i = True
      r = '1'
    elif i and not j and r == 'j' and p % 2 == 0:
      j = True
      r = '1'
    elif j and not k and r == 'k' and p % 2 == 0:
      k = True
      break

  r = '1'
  p = 0
  for c in s:      
    r = q[r + c]
    if r[0] == '-':
      r = r[1]
      p += 1

  passed = False
  if len(s) <= 3 and n == 1 and s != 'ijk':
    passed = False
  elif i and j and k:
    if r == '1' and (p * n) % 2 == 1:
      passed = True
    elif r == 'i' and n % 4 == 2:
      passed = True
    elif r == 'j' and n % 4 == 2:
      passed = True
    elif r == 'k' and n % 4 == 2:
      passed = True
  g.write('Case #' + str(count) + ': ' + ('YES' if passed else 'NO') + '\n')
  #print(r,p,n)
  count += 1
f.close()
g.close()
