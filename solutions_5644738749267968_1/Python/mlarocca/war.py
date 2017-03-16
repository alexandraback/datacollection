'''
Created on 12/apr/2014

@author: mlarocca
'''
from sys import argv
N_ROWS = 4

MULTIPLE_CARDS_ERROR = "Bad magician!"
NO_CARDS_ERROR = "Volunteer cheated!"

def read_input(f):
  lines = open(f, 'r')
  n = int(lines.readline().strip())
  for i in xrange(n):
    lines.readline()  #discard a line
    naomi = map(float, lines.readline().strip().split(" "))
    ken = map(float, lines.readline().strip().split(" "))
    
    yield i+1, naomi, ken  
    
def war(naomi, kevin):
  naomi = sorted(naomi)
  kevin = sorted(kevin)

  score_naomi = 0
  while len(naomi) > 0:
    n = naomi.pop()
    k_s = filter(lambda x: x > n, kevin)
    if len(k_s) == 0:
      score_naomi += 1
    else:
      k = min(k_s)
      i = kevin.index(k)
      kevin.pop(i)

  return score_naomi

def d_war(naomi, kevin):
  naomi = sorted(naomi)
  kevin = sorted(kevin)

  score_naomi = 0
  while len(naomi) > 0:
    k_t = kevin.pop()
    if naomi[0] > k_t:
      return score_naomi + len(naomi)
    elif naomi[-1] > k_t:
      naomi.pop()
      score_naomi += 1
    else:
      naomi.pop(0)

  return score_naomi
  
if __name__ == '__main__':
  for test_case, naomi, kevin in read_input(argv[1]):
    print "Case #%d: %d %d" % (test_case, d_war(naomi, kevin), war(naomi, kevin))
