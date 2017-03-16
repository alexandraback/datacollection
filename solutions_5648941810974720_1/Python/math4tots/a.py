try: input = raw_input
except NameError: pass

def solve(s):
  d = {ch: 0 for ch in map(chr, range(ord('a'), 1+ord('z')))}

  ns = []

  for c in s.lower():
    d[c] += 1

  def process(checkchar, text, num):
    while d[checkchar]:
      for c in text:
        d[c] -= 1
      ns.append(num)

  process('z', 'zero',  0)
  process('w', 'two',   2)
  process('u', 'four',  4)
  process('x', 'six',   6)
  process('g', 'eight', 8)
  process('o', 'one',   1)
  process('h', 'three', 3)
  process('f', 'five',  5)
  process('s', 'seven', 7)
  process('n', 'nine',  9)
  assert all(x == 0 for x in d.values()), d

  return ''.join(map(str, sorted(ns)))

for i in range(1, 1+int(input())):
  print('Case #%d: %s' % (i, solve(input())))

