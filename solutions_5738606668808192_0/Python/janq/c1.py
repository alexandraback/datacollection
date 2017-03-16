import random

N=16
J=50

def primes(n):
    """ Returns  a list of primes < n """
    sieve = [True] * n
    for i in xrange(3,int(n**0.5)+1,2):
        if sieve[i]:
            sieve[i*i::2*i]=[False]*((n-i*i-1)/(2*i)+1)
    return [2] + [i for i in xrange(3,n,2) if sieve[i]]

def valueInBase(v, base):
  ret = 0
  b = 1
  for i in range(len(v)):
    ret += b * v[i]
    b *= base
  return ret
    

P = primes(10000000)
vys = set()

while True:
  v = []
  v.append(1)
  for i in range(N-2):
    v.append(random.randint(0, 1))
  v.append(1)
  divisors = []      
  for b in range(2,11):
    h = valueInBase(v, b)   
    for div in P:
      if(div < h):
        if h%div ==0:
          divisors.append(div)
          break
    if (len(divisors) != b-1):
      break  
  if( len(divisors) != 9):
    continue

  line = ""
  for x in v:
    line = str(x) + line
  if line in vys:
    continue
  vys.add(line)
  for d in divisors:
    line += " " + str(d)
  print line
  if len(vys) == J:    
    break
