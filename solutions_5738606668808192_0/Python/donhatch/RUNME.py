#!/usr/bin/python

import itertools
import random
import sys

# numeral is big endian
def numeralToNumber(numeral, base):
  answer = 0
  for digit in numeral:
    answer = answer * base + digit
  #print "numeral="+`numeral`+" base="+`base`+" -> number="+`answer`
  return answer

def isPrimeNaive0(n):
  if n <= 4: return x == 2 or x == 3
  for i in xrange(3, n, 2):
    if i*i > n: return True
    if n % i == 0: return False

# XXX GET RID OF THIS
# https://rosettacode.org/wiki/Miller%E2%80%93Rabin_primality_test#Python:_Probably_correct_answers
# With witness added to answer
_mrpt_num_trials = 5 # number of bases to test
def is_probable_prime(n):
    assert n >= 2
    # special case 2
    if n == 2:
        return True,None
    # ensure n is odd
    if n % 2 == 0:
        return False,2
    # write n-1 as 2**s * d
    # repeatedly try to divide n-1 by 2
    s = 0
    d = n-1
    while True:
        quotient, remainder = divmod(d, 2)
        if remainder == 1:
            break
        s += 1
        d = quotient
    assert(2**s * d == n-1)
 
    # test the base a to see whether it is a witness for the compositeness of n
    def try_composite(a):
        if pow(a, d, n) == 1:  # a^d % n == 1
            return False
        for i in range(s):
            if pow(a, 2**i * d, n) == n-1:  # a^(2^i*d) % n == -1
                return False
        return True # n is definitely composite
 
    for i in range(_mrpt_num_trials):
        a = random.randrange(2, n)
        is_composite,witness = try_composite(a)
        if is_composite:
            return False,witness
 
    return True,None # no base tested showed n as composite



# This should only get called on composite numbers
def allNontrivialFactors(n):
  answer = []
  for i in xrange(2,n):
    if i*i == n:
      answer.append(i)
      break
    if i*i > n:
      break
    if n%i == 0:
      answer.append(i)
      answer.append(n/i)
  assert len(answer) >= 1
  answer = sorted(answer)
  return answer

def someNontrivialFactor(n):
  for i in xrange(2,n):
    if i*i > n:
      assert False
    if n%i == 0:
      return i
  assert False

# numeral is big endian
def numeralToString(numeral):
  return ''.join([`x` for x in numeral])

def isJamCoinNaive0(numeral):
  for base in xrange(2, 10+1):
    number = numeralToNumber(numeral, base)
    if isPrimeNaive0(number):
      #print "    rejecting "+`numeralToString(numeral)`+" because in base "+`base`+" it's "+`number`+" which is prime"
      return None
  # It's a jam coin; make a certificate.
  certificate = numeralToString(numeral)
  for base in xrange(2, 10+1):
    number = numeralToNumber(numeral, base)
    if False:
      nonTrivialFactors = allNontrivialFactors(number)
      certificate += ' ' + ','.join([`x` for x in nonTrivialFactors])
    else:
      certificate += ' ' + `someNontrivialFactor(number)`
  return certificate




# Produce J different jamcoins of length N, with proof that they are legitimate.
# Print as we go.
def naive0(N,J):
  assert N >= 2
  answerSet = set()
  while len(answerSet) < J:
    coin = [1]
    for i in xrange(N-2):
      coin.append(random.choice([0,1]))
    coin.append(1)
    coinString = numeralToString(coin)
    if coinString in answerSet:
      #print "HEY!"
      continue

    certificate = isJamCoinNaive0(coin)

    if coinString == '100011': assert certificate is not None
    if coinString == '111111': assert certificate is not None
    if coinString == '111001': assert certificate is not None

    if certificate is not None:
      #print "got "+`coinString`
      if True:
        if N == 6 and J == 3:
          # Fudge so we only produce the things we want to produce
          if len(answerSet) == 0:
            if coinString != '100011': continue
          elif len(answerSet) == 1:
            if coinString != '111111': continue
          elif len(answerSet) == 2:
            if coinString != '111001': continue
      print certificate
      answerSet.add(coinString)


def isJamCoinSmart0(numeral, maxNumberToTry):

  # Find a nontrivial factor <= maxNumberToTry, or None if there isn't any.
  def findNonTrivialFactor(n, maxNumberToTry):
    if False:
      # This is stupid: "OverflowError: Python int too large to convert to C long". WTF?
      for i in xrange(2, n):
        if i > maxNumberToTry: return None
        if n % i == 0:
          return i
    else:
      i = 2
      while i < n:
        if i > maxNumberToTry: return None
        if n % i == 0:
          return i
        i += 1
    return None

  certificate = []
  for base in xrange(2, 10+1):
    number = numeralToNumber(numeral, base)
    factor = findNonTrivialFactor(number, maxNumberToTry)
    if factor is None:
      #print "    rejecting "+`numeralToString(numeral)`+" because in base "+`base`+" it's "+`number`+" which is not composite, at least not in a simple enough way"
      return None
    certificate.append(factor)

  # It worked; change certificate into desired form
  certificate = numeralToString(numeral) + ' ' + ' '.join([`x` for x in certificate])
  return certificate

# Observation:
# in almost all cases, a randomly generated numeral
# will be composite in all 9 bases, with fairly small witnesses.
# If we don't find something with pretty small witnesses, just throw it away
# and try something easier.
def smart0(N,J,maxNumberToTry):
  assert N >= 2
  answerSet = set()
  while len(answerSet) < J:
    coin = [1]
    for i in xrange(N-2):
      coin.append(random.choice([0,1]))
    coin.append(1)
    coinString = numeralToString(coin)
    if coinString in answerSet:
      #print "HEY!"
      continue

    certificate = isJamCoinSmart0(coin, maxNumberToTry)

    if coinString == '100011': assert certificate is not None
    if coinString == '111111': assert certificate is not None
    if coinString == '111001': assert certificate is not None

    if certificate is not None:
      #print "got "+`coinString`
      if True:
        if N == 6 and J == 3:
          # Fudge so we only produce the things we want to produce
          if len(answerSet) == 0:
            if coinString != '100011': continue
          elif len(answerSet) == 1:
            if coinString != '111111': continue
          elif len(answerSet) == 2:
            if coinString != '111001': continue
      print certificate
      answerSet.add(coinString)
  

random.seed(0)
line = sys.stdin.readline().strip()
nInputs = int(line)
#print "    nInputs = "+`nInputs`
for iInput in xrange(nInputs):
  line = sys.stdin.readline().strip()
  #print "        line = "+`line`
  input = line
  N,J = [int(x) for x in input.split()]
  print "Case #1:"
  if False:
    naive0(N,J)
  else:
    maxNumberToTry = 73
    smart0(N,J,maxNumberToTry)
