# @author Carlos M. Pascal 
# @email cpascal at ac.tuiasi.ro
# Pr A, Round1C

#import timer
#@timer.timedFunction

input = 'D:\work\codejam2015\Round1C\A\A-small-attempt1.in'
input = 'D:\work\codejam2015\Round1C\A\A-large.in'
output = 'D:\work\codejam2015\Round1C\A\AA.txt'


def doJob(R, C, W): 
  x = 1
  if (C%W) == 0:
    x=0
  return R*(C/W)+W-1+x

  
fin = open(input)
fout = open(output, 'w')
no_cases = int(fin.readline())
for no in range(1, no_cases+1):
  R, C, W = fin.readline().split()
  R, C, W = int(R), int(C), int(W)
  #if no!=21:
   # pass
    #continue
  #print v
  result = doJob(R, C, W)
  
  msg = 'Case #{0}: {1}'.format(no, result)
  #if W<result:
  print R, C, W, msg
  fout.write(msg+'\n')


fin.close()
fout.close()