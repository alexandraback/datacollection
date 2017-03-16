t=input()
for j in xrange(t):
  n=input()
  if n==0:
    print "Case #"+str(j+1)+": INSOMNIA"
    continue
  digits=[False]*10
  nm=0
  while digits.count(False)>0:
    nm+=n
    ns=str(nm)
    for digit in xrange(10):
      if str(digit) in ns:
        digits[digit]=True
  print "Case #"+str(j+1)+": "+ns
  
