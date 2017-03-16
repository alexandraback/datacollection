#!/usr/bin/python -tt


def main(S,n):
  #n-value, which is the number of substrings with at least n consecutive consonants in the name.
  total = 0
  vowels = "aeiou"
  consonants = "bcdfghjklmnpqrstvwxyz"
  L = len(S)
  n = int(n)

  temp = ""
  for j in S:
    if j in vowels: temp = temp + "0"
    else: temp = temp + "1"

  readed = []

  posic = 0
  posic_anterior = -1
  posic = temp.find("1"*n,posic)
  while posic >= 0:
    total = total + (posic+1-(posic_anterior+1)) * (L-(posic+n)+1)
    '''
    for i in xrange(posic+1):
      for j in xrange(L-(posic+n)+1):
        if (i,j) not in readed:
          total += 1
          readed.append((i,j))
    '''
    posic_anterior = posic
    posic = temp.find("1"*n,posic+1)
  
  return total


if __name__ == '__main__':
  import sys
  T = int(sys.stdin.readline())
  for i in xrange(T):
    S,n = map(str,sys.stdin.readline().strip().split(" "))
    res = main(S,n)
    print "Case #%d: %s" % (i + 1, res)



