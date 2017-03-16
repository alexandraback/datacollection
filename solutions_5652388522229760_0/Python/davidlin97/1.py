
T = int(raw_input())

def solve(a):
  if a==0: return "INSOMNIA"
  b = 0
  count = 0
  saw = set()
  while count!=10:
    b += a
    for c in str(b):
      if c not in saw:
        saw.add(c)
        count += 1
  return b

for i in xrange(1, T+1):
  N = int(raw_input())
  print "Case #{}: {}".format(i, solve(N))