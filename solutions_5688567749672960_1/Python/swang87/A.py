import math
import itertools

infile = 'A-large.in'
outfile = 'A-large-out.txt'

 
vals = {}

def check(n):
  if n in vals:
    return vals[n]
  if n <= 20:
    return n
  if n % 10 == 0:
    return check(n-1)+1
  s = [int(i) for i in str(n)]
  if n <= 99:
    vals[n] = 10 + sum(s)
    return vals[n]
  l = int(math.floor(math.log10(n)))
  theMin = n
  revstr = ''.join(itertools.imap(str, s[::-1]))
  the99 = 10**l-1 
  for k in range(l):
    thestring = '1'+'0'*k+revstr[(k+1):]
    palindrome = thestring == thestring[::-1]
    theval = n % 10**(k+1) + int(thestring) - palindrome - the99 +check(the99)
    if theval < theMin:
      theMin = theval
  vals[n] = theMin
  return vals[n]
      
def main():
  out = open(outfile, 'w')
  f = open(infile)
  N = int(f.readline())
  for n in xrange(N):
    b = int(f.readline())
    num = check(b)
    out.write("Case #"+str(n+1)+": "+str(num)+"\n")


main()

