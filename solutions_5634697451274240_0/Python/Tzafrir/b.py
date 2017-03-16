from sys import stdin

def score(seq):
  last=seq[0]
  count=0
  for ch in seq:
    if ch != last:
      last=ch
      count+=1
  if last=='-':
    count+=1
  return count


for case in xrange(1,1+int(stdin.readline())):
    seq = stdin.readline().strip()
    print "Case #%d: %s" % (case, score(seq))