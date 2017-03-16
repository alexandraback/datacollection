T = input()

for t in range(1, T + 1):
  s = raw_input().strip()
  d = {}
  for c in s:
    d.setdefault(c, 0)
    d[c] += 1
  nums = [0 for i in range(10)]
  for c in 'ZEROONETWOTHREEFOURFIVESIXSEVENEIGHTNINE':
    d.setdefault(c, 0)

  nums[0] = d['Z']
  d['E'] -= d['Z']
  d['R'] -= d['Z']
  d['O'] -= d['Z']
  d['Z'] = 0

  nums[2] = d['W']
  d['T'] -= d['W']
  d['O'] -= d['W']
  d['W'] = 0

  nums[4] = d['U']
  d['F'] -= d['U']
  d['O'] -= d['U']
  d['R'] -= d['U']
  d['U'] = 0

  nums[6] = d['X']
  d['S'] -= d['X']
  d['I'] -= d['X']
  d['X'] = 0

  nums[8] = d['G']
  d['E'] -= d['G']
  d['I'] -= d['G']
  d['H'] -= d['G']
  d['T'] -= d['G']
  d['G'] = 0

  nums[1] = d['O']
  d['N'] -= d['O']
  d['E'] -= d['O']
  d['O'] = 0

  nums[3] = d['T']
  d['H'] -= d['T']
  d['R'] -= d['T']
  d['E'] -= d['T']
  d['E'] -= d['T']
  d['T'] = 0

  nums[5] = d['F']
  d['I'] -= d['F']
  d['V'] -= d['F']
  d['E'] -= d['F']
  d['F'] = 0

  nums[7] = d['S']
  d['E'] -= d['S']
  d['V'] -= d['S']
  d['E'] -= d['S']
  d['N'] -= d['S']
  d['S'] = 0

  nums[9] = d['I']

  ans = ''
  for i in range(10):
    ans += str(i) * nums[i]

  print 'Case #%d: %s' % (t, ans)
