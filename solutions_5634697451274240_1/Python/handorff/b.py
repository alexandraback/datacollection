import itertools

def reverse(s, i):
  return s[:i][::-1] + s[i:]

def invert(s, i):
  out = ""
  for j in xrange(i):
    if s[j] == '+':
      out += "-"
    else:
      out += "+"
  return out + s[i:]

def flip(s, i):
  r = reverse(s, i)
  return invert(r, i)

def test(s, p):
  for idx in p:
    s = flip(s, idx + 1)
  return s == "+" * len(s)

def solve(case):
  i = 1
  l = len(case)

  if case == "+" * l:
    return 0

  while True:
    all_p = itertools.product(range(l), repeat=i)
    for p in all_p:
      if test(case, p):
        return i
    i += 1

def solve2(case):
  case = case[::-1]
  last = "+"
  total = 0

  for i in xrange(len(case)):
    if case[i] != last:
      total += 1
    last = case[i]
  return total

cases = []
t = int(raw_input())
for i in xrange(t):
  cases.append(raw_input())

for i, case in enumerate(cases):
  print "Case #%d: %d" % (i + 1, solve2(case))
