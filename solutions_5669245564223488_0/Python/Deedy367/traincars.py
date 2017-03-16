import sys
from IPython.core.debugger import Tracer
import re
import math
from operator import mul

def hasIntersection(a, b):
  return not set(a).isdisjoint(b)

def reducer(doubles):
  newdoubs = []
  delete = []
  for x in xrange(len(doubles)):
    for y in xrange(x+1,len(doubles)):
      if doubles[x][0] == doubles[y][-1]:
        delete.append(x)
        delete.append(y)
        newdoubs.append(doubles[y]+doubles[x][1:])
        break
      elif doubles[x][-1] == doubles[y][0]:
        delete.append(x)
        delete.append(y)
        newdoubs.append(doubles[x]+doubles[y][1:])
        break
    else:
      continue
    break

  doubles = [doubles[i] for i in xrange(len(doubles)) if not i in delete]
  for j in newdoubs:
    doubles.append(j)
  return doubles

def traincars(f):
  soln = ''
  cases = int(f.readline())
  for case in xrange(cases):
    no_cars = int(f.readline())
    cars = f.readline().strip().split(' ')
    new_cars = []
    for c in cars:
      new_cars.append(re.sub(r'(.)\1+', r'\1', c))
    # Tracer()()
    midchars = ''
    sidechars = ''
    for c in new_cars:
      if len(c) > 1:
        midchars += c[1:-1]
        sidechars += (c[0] + c[-1])
      else:
        sidechars += c[0]
    if hasIntersection(sidechars, midchars):
      soln += 'Case #{0}: 0\n'.format(case+1)
      continue
    else:
      new_cars = [x[0] + x[-1] if len(x) > 1 else x for x in new_cars ]
      singles = [x for x in new_cars if len(x) == 1]
      doubles = [x for x in new_cars if len(x) > 1]
      if not len(set(doubles)) == len(doubles):
        soln += 'Case #{0}: 0\n'.format(case+1)
      imp = False
      for x in xrange(len(doubles)):
        for y in xrange(x+1,len(doubles)):
          if doubles[x][0] == doubles[y][0] or doubles[x][1] == doubles[y][1]:
            imp == True
      if imp:
        soln += 'Case #{0}: 0\n'.format(case+1)
        continue
      else:
      # Tracer()()

        while True:
          newdoubs = reducer(doubles)
          if len(newdoubs) == len(doubles):
            break
          else:
            doubles = newdoubs
        # Tracer()()
        singlecount = {}
        for s in singles:
          if not s in singlecount:
            singlecount[s] = 0
          singlecount[s] += 1
        accum = []
        singlescounted = set({})
        for i in doubles:
          for m in i:
            if m in singlecount:
              accum.append(math.factorial(singlecount[m]))
              singlescounted.add(m)

        # Tracer()()
        singlesleft = [s for s in singles if not s in singlescounted]
        singlecount = {}
        for s in singles:
          if not s in singlecount:
            singlecount[s] = 0
          singlecount[s] += 1
        for s in singlecount:
          if singlecount[s] > 1:
            accum.append(math.factorial(singlecount[s]))
        accum.append(math.factorial(len(doubles) + len(set(singlesleft))))
        # Tracer()()
        res = reduce(mul, accum, 1) % 1000000007
        if not case + 1 == 25:
          soln += 'Case #{0}: {1}\n'.format(case+1, res)


    # soln += 'Case #{0}: {1}\n'.format(case+1, sol)
  return soln

def writeOutput(file, soln):
  file.write(soln)
  file.close()

if __name__ == '__main__':
  f = open(sys.argv[1])
  soln = traincars(f)
  f.close()
  g = open("output.txt", "w")
  writeOutput(g, soln)

