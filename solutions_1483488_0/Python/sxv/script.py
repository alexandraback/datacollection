f = open('input.in','r')
o = open('output.txt', 'w+')

numtests = int(f.readline())
testcount = 0

while testcount < numtests:
  testcount += 1
  
  ab = f.readline().split()
  a = int(ab[0])
  b = int(ab[1])
  
  results = 0
  for n in range(a,b+1):
    m = str(n)[-1] + str(n)[0:-1]
    while str(n) != m:
      if m[0] != '0':
        if a <= n < int(m) <= b:
          results += 1
      m = m[-1] + m[0:-1]
      
  o.write('Case #'+str(testcount)+': '+str(results)+'\n')
  print 'Case #'+str(testcount)+': '+str(results)