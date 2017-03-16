'''
Created on 12/apr/2014

@author: mlarocca
'''
from sys import argv
from json import loads
from minefield_generator import make_key

CLICK_MARK = "c"
     
def read_input(f):
  lines = open(f, 'r')
  n = int(lines.readline().strip())
  for i in xrange(n):
    r, c, m = map(int, lines.readline().strip().split(" "))
    
    yield i+1, r, c, m
  lines.close()
  
if __name__ == '__main__':
  valids = loads(open('valids.txt', 'r').read())
  
  for test_case, r, c , m in read_input(argv[1]):
    print "Case #%d:" % test_case
    k = make_key(r, c, m)
    if k in valids:
      print "\n".join(valids[k])
    else:
      print "Impossible"

