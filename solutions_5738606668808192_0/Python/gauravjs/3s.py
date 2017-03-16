print "Case #1:"

n=16
j=50

for i in range(j):
  x = str(bin(i))[2:]
  y = '0' * (6 - len(x)) + x
  
  s = '1' + y + '11' + y + '1'
  for k in range(2,11):
    s += ' ' + str(k**(n/2) + 1)
  print s
