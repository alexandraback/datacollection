# I love Cristina Luminea
def solve(C, F, X, rate, time):
  while X / rate >= (C / rate) + (X / (rate+F)):
    time += C / rate
    rate += F
  return time + (X / rate)

T = int(raw_input())
for t in range(T):
  C, F, X = map(float, raw_input().split())
  print 'Case #%i: %.7f' % (t+1, solve(C, F, X, 2, 0))
