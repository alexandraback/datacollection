import sys
import math

primes = [2]
w = 0
n = 0
jj = 0
p = [1] * 35
ans = [1] * 9

def dg(q):
  global p, primes, n, jj, w
  if (q == n - 1):
    f = True
    for i in range(2, 11):
      tmp = 1
      base = i
      for j in range(1, n):
        tmp = tmp + base * p[j]
        base = base * i
      ff = False
      for j in range(0, w):
        if (tmp % primes[j] == 0):
          ff = True
          ans[i - 2] = primes[j]
          break
      if (not ff):
        f = False
        break
    if (f):
      for j in range(0, n):
        sys.stdout.write(str(p[n-j-1]))
      sys.stdout.write(' ')
      sys.stdout.write(str(ans[0]))
      for j in range(1, 9):
        sys.stdout.write(' ')
        sys.stdout.write(str(ans[j]))
      sys.stdout.write('\n')
      jj = jj -1
      if (jj == 0):
        exit(0) 
  else:
    p[q] = 0
    dg(q + 1)
    p[q] = 1
    dg(q + 1)

if __name__ == '__main__':
  print 'Case #1:'
  n = input()
  jj = input()
  for i in range(3, 10000):
    f = True
    for j in range(0, w):
      if (i % primes[j] == 0):
        f = False
        break
      elif (primes[j] > math.sqrt(i)):
        break
    if (f):
      w = w + 1
      primes.insert(w, i)
  dg(1)
