# qualc.py

import itertools

def rev(s):
  ret = 0
  while s > 0:
    ret*=10
    ret += (s%10)
    s/=10
  return ret

def ispalin(s):
  digits = getdigits(s)
  return all(digits[i] == digits[-(i+1)] for i in xrange(len(digits)))
    
def getdigits(s):
  ret = []
  while s>0:
    ret.append(s%10)
    s/=10
  return ret

def numdigits(s):
  ret = 0
  while s>0:
    ret+=1
    s/=10
  return ret

def palindromify(k, s):
  if k%2 == 0:
    return s*(10**(k/2)) + rev(s)
  if k%2 != 0:
    return s*(10**(k/2)) + rev(s/10)

def firstdigits(n, ln, l):
  return n/(10**(ln - l))

def prt(k, s):
  # returns list of k-digit palindromes with palindromic squares
  # that start with prefix 's'
  #print k, s
  l = numdigits(s)
  if l==(k+1)/2:
    pot = palindromify(k, s)
    if ispalin(pot*pot):
      print pot*pot
    return
  else:
    l = numdigits(s)
    r = rev(s)
    rp = (r*r)%(10**l)
    sp = rev(rp)
    ls = numdigits(sp)
    sp *= (10**(l-ls))
    
    lb = s*s
    ub = (s+1)*(s+1)
    
    ll = numdigits(lb)
    lu = numdigits(ub)
    
    firstl = firstdigits(lb, ll, l)
    firstu = firstdigits(ub, lu, l)

    #print '----', s, r, rp, lb, ub, ll, lu, firstl, firstu
    
    if ll == lu:
      if firstl <= sp and sp <= firstu:
	for i in xrange(0, 3):
	  prt(k, 10*s+i)
    else:
      if firstl <= sp or sp <= firstu:
	for i in xrange(0, 3):
	  prt(k, 10*s+i)

for i in xrange(1, 11):
  prt(i, 1)
  prt(i, 2)
  prt(i, 3)
  