
inf = open('2.in')
numtests = int(inf.readline())

for testindex in xrange(numtests):
  fcost, fgain, target = tuple([float(x) for x in inf.readline().split(' ')])
  #print fcost, fgain, target

  t = 0
  cps = 2
  cookies = 0
  
  farmroi = fcost / fgain
  
  while True:
    nextf = fcost / cps
    ttarget = (target - cookies) / cps
    
    if ttarget - farmroi < nextf:
      print 'Case #{0}: {1:.7f}'.format(testindex+1, t + ttarget)
      break
 
    t += nextf
    cookies += nextf * cps
    cookies -= fcost
    cps += fgain
    
    #print t, cookies