import sys
import itertools
import numpy as np
import math
from copy import copy
f=open(sys.argv[1],'r')
ncases=int(f.readline().strip('\n'))
def prKGivenCombo(K,combo,samplings=100):
  l=len(combo)
  #Just estimate it by monte carlo
  ctr=0
  for i in xrange(samplings):
    if np.prod(combo[np.random.random_sample(l)>.5])==K:
      ctr=ctr+1
  return ctr/float(samplings)




print "Case #1:"
R,N,M,K = [int(x) for x in f.readline().strip().split()]
ncases=R
for icase in xrange(ncases):
  Ks=[int(x) for x in f.readline().strip().split()]
  drawn=[x for x in xrange(2,M+1)]
  allcombos=[]
  #Pick one after another until all done
  for j in itertools.combinations_with_replacement(drawn,N):
    allcombos.append(np.array(j))
  prPerCombo=1./((M-1)**N)
  prKvec=np.zeros((M-1)**N)
  #Iterate over all combinations, find pr K given Combo for each K
  for ctr,combo in enumerate(allcombos):
    totpr=1.
    for k in Ks:
      totpr=totpr*prKGivenCombo(k,combo)
    prKvec[ctr]=totpr
  #Now work out the bayesian estimated prob of each
  prComboGivenKs=(prKvec*prPerCombo)/np.sum(prKvec)
  #print allcombos
  #print prKvec
  #print prComboGivenKs
  #Output the most likely combination
  o=np.argmax(prComboGivenKs)
  print ''.join([str(int(x)) for x in allcombos[o]])
