def process():
  K, L, S = map(int, raw_input().split())
  kB = raw_input()
  tS = raw_input()
  overlap = 0
  i = L - 1
  while i > 0:
    if tS[:i] == tS[-i:]:
      overlap = i
      break
    i -= 1

  repeat = (S - L) / (L - overlap) + 1

  prob = 1.0
  for i in xrange(L):
    prob *= kB.count(tS[i]) * 1.0 / K
 
  # SPL
  if prob == 0.0:
    return 0.0

  return repeat*1.0-prob*(S-L+1)

def main():
  tC = int(raw_input())
  tc = tC
  while tc > 0:
    tc -= 1
    ans = process()
    print u"Case #{}: {}".format(tC-tc, ans)

if __name__ == "__main__":
  main()
