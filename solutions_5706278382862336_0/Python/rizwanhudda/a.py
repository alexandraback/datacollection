import sys
def gcd(x, y):
  while y>0:
    x, y = y, x%y
  return x

#sys.stdin  = open("A-sample.in")
#sys.stdout = open("A-sample.out", "w")
sys.stdin  = open("A-small-attempt5.in")
sys.stdout = open("A-small-attempt5.out", "w")
num_cases = input()

for case_no in range(1, num_cases+1):
  p, q = map(int, raw_input().split("/"))
  g = gcd(p, q)
  p, q = p/g, q/g
  # print p, q, g
  # lowest power of 2 >= q
  q2 = 0
  while (2**q2) < q:
    q2 += 1
  #print q2
  if (q2>40) or (p == 0) or ((2**q2) != q):
    print 'Case #%d: impossible' % (case_no)
  else:
    # highest power of 2 in x
    p2 = 0
    while (2**p2) <= p:
      p2 += 1
    #print p, p2-1, q, q2
    print 'Case #%d: %d' % (case_no, q2-p2+1)