import math

n = int(raw_input())

def gcd(a,b):
  if a==b:
    return a
  if a<b:
    return gcd(b,a)
  return gcd(a-b, b)

def powerlessindex(n):
  k = 1
  power = 0
  while k <= n:
    k *= 2
    power += 1
  return power-1

def powerless(n):
  k = 1
  while k < n:
    k *= 2
  return k

for i in range(n):
  [a,b] = [int(x) for x in raw_input().split('/')]
  d = gcd(a,b)
  a /= d
  b /= d
  if powerless(b) != b:
    answer = "impossible"
  else:
    answer = powerlessindex(b) - powerlessindex(a)
  print "Case #%s: %s"%(i+1, answer)
