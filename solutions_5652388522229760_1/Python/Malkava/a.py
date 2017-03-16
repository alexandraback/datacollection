T = int(raw_input())
case = 1

def add_to_set(n, nset):
  while n > 0:
    d = n % 10
    nset[d] = 1
    n /= 10
  return sum(nset)

case = 1
while case <= T:
  n = int(raw_input())
  if n == 0:
    print("Case #%d: INSOMNIA" % (case))
    case += 1
    continue
  nset = [0] * 10
  m = n
  while add_to_set(n, nset) < 10: n += m
  print("Case #%d: %d" % (case, n))
  case += 1
