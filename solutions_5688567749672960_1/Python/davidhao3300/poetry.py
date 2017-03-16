f = open('A-large.in')
o = open('output.txt', 'w')
n = int(f.readline())

for i in range(n):
  x = int(f.readline().strip())
    
  t = 0
  #print x
  while x > 9:
    p = 10 ** (len(str(x))/2)
    t += (x-1)%p
    if x % p == 0:
      x = (x/p-1)*p+1
    else:
      x = x/p*p+1
    alt = int(str(x)[::-1])
    if alt >= x or x % 10 == 0:
      x -= 1
    else:
      x = alt
    t += 1
    if x == 10 ** (len(str(x))-1):
      x -= 1
      t += 1
    #print x
  t += x
  o.write('Case #'+str(i+1)+': '+str(t)+'\n')

o.close()
f.close()