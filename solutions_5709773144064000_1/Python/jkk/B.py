import sys

cases = int(sys.stdin.readline())
for case_no in range(1, cases+1):
  C, F, X = [float(val) for val in sys.stdin.readline().split()]
 
  fcost = 0
  best = X / 2.0
  k = 0
  while True:
    k += 1
    fcost += C / (2.0 + F*(k - 1.0))
    ecost = X / (2.0 + F*k)
    if best > fcost + ecost:
      best = fcost + ecost
    else:
      break
  
  print("Case #{}: {:.7f}".format(case_no, best))

