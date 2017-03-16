'''
Created on 12/apr/2014

@author: mlarocca
'''
from sys import argv

def compute(A, B, K):
  if B < A:
    tmp = A
    A = B
    B = tmp

  if K >= A and K >= B:
    return A * B

  tot = 0

  for a in xrange(A):
    for b in xrange(B):
      if a & b < K:
        tot += 1

  return tot


def read_input(f):
  lines = open(f, 'r')
  N = int(lines.readline().strip())
  for i in xrange(N):
    
    A, B, K = lines.readline().strip().split(" ")
    
    yield i+1, A, B, K  
    
 

  
if __name__ == '__main__':
  for test_case, A, B, K in read_input(argv[1]):

    #print bin(int(A))
    #print bin(int(B))
    #print bin(int(K))
    #print " - - - "
    res = compute(int(A), int(B), int(K))
    print "Case #%d: %d" % (test_case, res)
