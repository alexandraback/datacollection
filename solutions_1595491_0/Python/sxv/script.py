f = open('input3.in','r')
o = open('output3.txt', 'w+')

numtests = int(f.readline())
testcount = 0

while testcount < numtests:
  testcount += 1
  exit = 0
  results = 0
  linesplit = f.readline().split()
  n = int(linesplit[0])
  s = int(linesplit[1])
  p = int(linesplit[2])
  if p == 0:
    results = n
    print 'p equals 0 for case',str(testcount)
  else:
    for score in linesplit[3:]:
      if int(score) != 0:
        d,m = divmod(int(score),3)
        if m == 0:
          if d >= p: results += 1
          elif d+1 == p and s > 0:
            results += 1
            s -= 1
        elif m == 1:
          if d+1 >= p: results += 1
        elif m == 2:
          if d+1 >= p: results += 1
          elif d+2 == p and s > 0:
            results += 1
            s -= 1

  o.write('Case #'+str(testcount)+': '+str(results)+'\n')
  #print 'Case #'+str(testcount)+': '+str(results)