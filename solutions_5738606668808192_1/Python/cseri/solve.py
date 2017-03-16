
# https://stackoverflow.com/questions/4114167/checking-if-a-number-is-a-prime-number-in-python
from math import sqrt
from itertools import count, islice

# changed!
# @returns: 1 if prime, a divisor if not
def isPrime(n):
  if n < 2: return False
  for number in islice(count(2), min(500, int(sqrt(n)-1))):
    if not n%number:
      return number
  return 1


def solve(n, j):
  i = 0
  while j > 0:
    coinmiddle = (bin(i)[2:].zfill(n-2))
    if len(coinmiddle) > n - 2:
      print "Less coins were found than needed."
      exit(1)
    coincandidate = "1" + coinmiddle + "1"
    coingood = True
    coindivisors = []
    for base in range(2, 11):
      coininbase = int(coincandidate, base)
      #print "in base " + str(base) + " : " + str(coininbase)
      divisor = isPrime(coininbase)
      if divisor == 1:
        coingood = False
        break
      else:
        coindivisors.append(str(divisor))

    if coingood:
      # Print solution.
      print coincandidate + " " + (" ".join(coindivisors))
      j -= 1

    i += 1


#n = 6 ; j = 5
#n = 16; j = 50
n = 32; j = 500

print "Case #1:"
solve(n, j)

