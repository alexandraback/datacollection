mat = [
[4, 2, 4, True],
[4, 2, 6, True],
[4, 2, 8, True],
[4, 2, 10, True],
[4, 2, 12, True],
[4, 2, 14, True],
[4, 2, 16, True],
[4, 2, 18, True],
[5, 3, 5, True],
[5, 3, 10, False],
[5, 3, 15, False],
[6, 3, 6, True],
[6, 3, 8, True],
[6, 3, 10, True],
[6, 3, 12, True],
[6, 3, 14, True],
[6, 3, 16, True],
[6, 3, 18, True]
]

if __name__ == '__main__':
  with open('input') as fi:
    lines = fi.read().splitlines()

  tests = int(lines[0])
  for i in xrange(tests):
    x, r, c = [int(j) for j in lines[i+1].split()]
    found = True
    for val in mat:
      if x == val[0] and sorted([r,c])==val[1:3]:
        print 'Case #%s: %s' %(i+1, 'RICHARD' if val[3] else 'GABRIEL')
        break
    else:
      found = False

    if found:
      continue
     
    if r * c % x != 0:
      ric = True
    elif r < x and c < x:
      ric = True
    elif x <= 2:
      ric = False
    elif x >= 7:
      ric = True
    elif r*2+1<=x or c*2+1<=x:
      ric = True
    elif r >= x and c >= x:
      ric = False
    elif x == 3 and (r >= 2 or c >= 2):
      ric = False
    elif (x+1)/2 < min(r,c):
      ric = False
    else:
      ric = False
    print 'Case #%s: %s' %(i+1, 'RICHARD' if ric else 'GABRIEL')
