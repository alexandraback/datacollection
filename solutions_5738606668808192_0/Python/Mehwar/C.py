import sys
cin = sys.stdin.readline
def readints():
  return map(int, cin().split())
INF = sys.maxsize
NINF = -sys.maxsize - 1
#----------------------------------------------------------------------
from copy import deepcopy
from math import sqrt

# Even ones guarantees that odd bases are not prime
def evenones(x):
  return len([c for c in x if c == '1']) % 2 == 0

def appendone(x):
  return x + '1'
def appendzero(x):
  return x + '0'

def get_divisor(x):
  if x <= 1: return -1
  for i in xrange(2, int(sqrt(x)) + 1):
    if x % i == 0:
      return i
  return -1  # number is prime

def baseval(jamcoin, base):
  if base == 10: return int(jamcoin)
  k = 0
  ans = 0
  for c in jamcoin[::-1]:
    ans += pow(base, k) * (ord(c) - ord('0'))
    k += 1
  return ans

def jamcoinbuild(curr, maxi):
  if curr == maxi - 1:
    return ['0', '1']
  if curr == 16:
    return ['0' * (maxi - curr), '1' * (maxi - curr)]

  sub = jamcoinbuild(curr + 1, maxi)
  sec = deepcopy(sub)
  return map(appendzero, sub) + map(appendone, sec)

def output_real_jamcoins(jamcoins):
  cnt = 0
  done = False
  for jamcoin in sorted(jamcoins):
    if not evenones(jamcoin): continue
    jamcoin = '1' + jamcoin + '1'
    oline = [jamcoin]
    for base in xrange(2, 10 + 1):
      val = baseval(jamcoin, base)
      divisor = get_divisor(val)
      if divisor == -1: break
      oline.append(str(divisor))
    if len(oline) == 10:
      cnt += 1
      print ' '.join(oline)
      # oline[0] = jamcoin[::-1]  # reverse jamcoin is also jam, with same divisors! -- really?
      # print ' '.join(oline)
      # print cnt
    if cnt == J:
      return


T = int(cin())
for _t in xrange(T):
  print "Case #1:"
  N, J = readints()
  jamcoins = jamcoinbuild(0, N - 2)
  output_real_jamcoins(jamcoins)


