mat = [
  [],
  [0, 1, 2, 3, 4],
  [0, 2, -1, 4, -3],
  [0, 3, -4, -1, 2],
  [0, 4, 3, -2, -1]
]

def calc(t, pos, req, till_end):
  cur = 1
  for i in xrange(pos, len(t)):
    if cur < 0:
      cur = -1 * mat[-cur][int(t[i])]
    else:
      cur = mat[cur][int(t[i])]
    if cur == req and not till_end:
      return cur, i+1
  return cur, len(t)

if __name__ == '__main__':
  with open('input.in') as fi:
    lines = fi.read().splitlines()

  tests = int(lines[0])
  for i in xrange(tests):
    x = int(lines[1+i*2].split()[1])
    if x >= 16:
      x = x % 12 + 12
      while x < 12:
        x += 4
  
    t = lines[2+i*2].replace('i','2').replace('j','3').replace('k','4') * x
    yes = False

    cur, pos = calc(t, 0, 2, False)
    if pos != len(t) and cur == 2:
      cur, pos = calc(t, pos, 3, False)
      if pos != len(t) and cur == 3:
        cur, pos = calc(t, pos, 4, True)
        if cur == 4:
          yes = True
      
    print 'Case #%s: %s' %(i+1, 'YES' if yes else 'NO')
