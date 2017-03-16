import copy

inf = open('4.in')
numtests = int(inf.readline())


def nscore(numlogs, nlogs, klogs):
  score = 0
  for i in xrange(numlogs):
    nlog = nlogs[-1]
    nlogs = nlogs[:-1]
    
    if klogs[-1] < nlog:
      klogs = klogs[1:]
      score +=1
      continue
      
    for k in xrange(len(klogs)):
      if klogs[k] > nlog:
        klogs = klogs[:k] + klogs[k+1:]
        break
  return score
  
  
def dscore(numlogs, nlogs, klogs):
  score = 0
  for i in xrange(numlogs):
    klog = klogs[0]
    klogs = klogs[1:]

    for n in xrange(len(nlogs)):
      if nlogs[n] > klog:
        nlogs = nlogs[:n] + nlogs[n+1:]
        score += 1
        break
      
  return score
  
  
for testindex in xrange(numtests):
  numlogs = int(inf.readline())
  nlogs = sorted([float(x) for x in inf.readline().split(' ')])
  klogs = sorted([float(x) for x in inf.readline().split(' ')])
  
  n = nscore(numlogs, copy.copy(nlogs), copy.copy(klogs))  
  d = dscore(numlogs, copy.copy(nlogs), copy.copy(klogs))
  
  print 'Case #{0}: {1} {2}'.format(testindex + 1, d, n)