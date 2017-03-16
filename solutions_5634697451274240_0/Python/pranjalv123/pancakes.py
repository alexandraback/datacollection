import numpy


d = {'+':1, '-':0}

def pancakes(s):
    n = sum(abs(numpy.diff([d[i] for i in s])))
    if s[-1] == '-':
        n += 1
    return n


t = int(raw_input())  # read a line with a single integer

for n in xrange(1, t + 1):
  s = raw_input()
  print "Case #{}: {}".format(n, pancakes(s))
