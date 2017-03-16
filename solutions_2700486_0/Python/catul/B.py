from operator import itemgetter

def debug_show(cubes, X, Y):
  dbg = True
  if not dbg:
    return

  lines = []
  for i in xrange(10):
    lines.append("."*80)

  for x,y in cubes:
    if (x,y) == (X,Y):
      add = "O"
    else:
      add = "X"
    x += 40
    lines[y] = lines[y][:x] + add + lines[y][x+1:]

  for line in lines[::-1]:
    if "X" in line or "O" in line:
      print line
  print

def slide(cubes, x, y):
  dbg = False
  if (dbg): print "slide x=%d y=%d" % (x,y)
  if (dbg): print cubes

  if y == 0:
    if (dbg): print "reached ground"
    cubes.append((x,y))
    return cubes, 1

  # if blocked down, try to slide:
  if (x, y-2) in cubes or (x+1,y-1) in cubes or (x-1,y-1) in cubes:
    n = 0
    if (x-1, y-1) in cubes:
      # cannot slide left, try to slide right...
      if (x+1, y-1) in cubes:
        # cannot slide right either, done.
        if (dbg): print "NO SLIDE"
        cubes.append((x,y))
        return cubes, 1
      else:
        n += 1
    else:
      if (x+1, y-1) in cubes:
        n += 1
      else:
        n += 2

    if n == 1:
      # if sliding was possible on one side only, do it
      if (x-1, y-1) in cubes:
        if (dbg): print "slide right"
        return slide(cubes, x + 1, y - 1)
      else:
        if (dbg): print "slide left"
        return slide(cubes, x - 1, y - 1)
    else:
      # sliding both sides possible
      c1, type = slide(cubes[:], x - 1, y - 1)
      if type != 1:
        print "DOUBLE SLIDE"
      c2, type = slide(cubes[:], x + 1, y - 1)
      if type != 1:
        print "DOUBLE SLIDE"
      if (dbg): print "slide both sides :"
      if (dbg): print c1
      if (dbg): print c2
      return [c1, c2], 2

  else:
    return slide(cubes, x, y - 1)


def main():
  dbg = False
  #f = open('B-sample.txt', 'r')
  #f = open('B-small-attempt0.in', 'r')
  f = open('B-small-attempt1.in', 'r')
  #f = open('B-small-practice-2.in', 'r')
  data = f.readlines()
  T = int(data[0])
  line = 1
  while line <= T:
    N, X, Y = [int(x) for x in data[line].split()]
    combos = []
    ok = 0

    # appetizer
    combos.append([(0,0)])
    N -= 1

    for i in xrange(N):
      #print combos
      newcombos = []

      if (dbg): print "Diamond #%d" % (i+1)
      for cubes in combos:
        # start at highest Y + ...
        maxy = max(cubes, key=itemgetter(1))[1]
        if (dbg): print "MAX Y = " + str(maxy)
        x = 0
        y = maxy + 3
        new, type = slide(cubes, x, y)
        if (dbg): print "---->"
        if (dbg): print new
        if (dbg): print type
        if type == 1:
          newcombos.append(new)
        else:
          newcombos.extend(new)

      combos = newcombos

    if (dbg): print combos

    for cubes in combos:
      debug_show(cubes, X, Y)

    total = len(combos)
    for cubes in combos:
      if (X,Y) in cubes:
        ok += 1
    if (dbg): print "total = %d  OK = %d" % (total, ok)
    proba = 1. * ok / total
    print "Case #%d: %.7f" % (line, proba)
    line += 1

if __name__ == "__main__":
    main()
