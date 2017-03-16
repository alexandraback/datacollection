#!/usr/bin/env python
import os
import sys
import time
#from   mpmath import     mp
#mp.dps = 100

tStart = time.time()

filename = 'input.txt'
filename = 'A-small-attempt1.in'


ifile = open(filename)
data  = ifile.read()
ifile.close()

lines   = data.splitlines()
n_cases = int(lines[0])
lines   = lines[1:]

print '\n n_cases = ', n_cases

verbose = 0
 
#--------------------------------------------------------------------------------
cases = []
for nc in xrange(n_cases):
  line = lines[0].split()
  A = int(line[0])
  N = int(line[1])
  line = lines[1].split()
  sizes = [int(x) for x in line]
  lines = lines[2:]

  if len(sizes) != N:
    print '\n ERROR \n'
    exit(0)

  sizes.sort()
  cumsum = [A]
  for x in sizes[:-1]:
    cumsum.append(cumsum[-1]+x)

  if verbose:
    print ''
    print A
    print sizes
    print cumsum
    print ''
 
  if A == 1:
    result = sum([int(x>0) for x in sizes])
  else:
    mark = [0 for k in xrange(N)]
    k = 0
    while k < len(sizes):
      if verbose:
        print k
      if sizes[k] >= cumsum[k]:
        M      = cumsum[k]-1
        sizes  = sizes[:k]    +  [M] + sizes[k:]
        cumsum = cumsum[:k+1] +  [x+M for x in cumsum[k:]]
        mark   = mark[:k]     +  [1] + mark[k:]
      else:
        k += 1
  
      if verbose:
        print sizes 
        print cumsum
        print mark
        raw_input()
  
    result = 0
    if sum(mark) > 0:
      k = len(mark)-1
      while k >= 0:
        #print k, len(mark), x
        x = mark[k]
        if x == 1:
          cum1 = sum(mark[k:])
          cum0 = len(mark[k:])-cum1
          if cum0 < cum1:
            mark    = mark[:k]
            result += cum0
            k       = len(mark)-1
          else:
            k += -1
        else:
          k += -1
      result += sum(mark)
        

  #print 'result = ', result
  cases.append(str(result))

print ''


#--------------------------------------------------------------------------------
print '\n\n--- Results --------------------------------------------------------\n'
ofile = open('output.txt','w')
for k,solution in enumerate(cases):
  text = 'Case #%d: %s '%(k+1,solution)
  print text
  ofile.write(text+'\n')
ofile.close()

print '\n Run time = ' + str((time.time() - tStart))



