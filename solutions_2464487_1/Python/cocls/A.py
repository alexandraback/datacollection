import math

FILE_IN = "A-large.in"
FILE_OUT = "A-large.out"

def isqrt(n):
  if n == 0:
    return 0
  l = len(bin(n))-2
  x = 2**((l+1)//2)
  while True:
    y = (x + n//x)/2
    if y >= x:
      return x
    x = y

def make(r, t):
  b = 2*r-1
  delta = b*b + 8*t
  sdelta = isqrt(delta)
  return (sdelta - b)//4

with open(FILE_IN, "r") as file_in:
  with open(FILE_OUT, "w") as file_out:
    test_case = int(file_in.readline().strip())
    for t in xrange(test_case):
      print 'test', t
      
      (a, b) = map(int, file_in.readline().split())
      ans = make(a, b)

      file_out.write("Case #%d: %d\n" % (t+1, ans))
