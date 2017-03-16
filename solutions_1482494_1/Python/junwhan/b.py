import sys

def calculate(levels):
  stars = steps = 0
  done = {}

  while stars < 2 * len(levels):
    best = None
    for i, (star1, star2) in enumerate(levels):
      if i not in done:
        if star2 <= stars:
          best = (i, 2, 2)
          break
        elif star1 <= stars:
          if best is None or (best[1] == 1 and levels[best[0]][1] < star2):
            best = (i, 1, 1)
      elif done[i] == 1:
        if star2 <= stars:
          best = (i, 2, 1)

    if best is None:
      return None

    stars += best[2]
    steps += 1
    done[best[0]] = best[1]

  return steps

with open(sys.argv[1]) as fin:
  with open('output', 'w') as fout:
    N = levels = None
    for i, line in enumerate(fin):
      if i > 0:
        if i % 2 == 1:
          N = int(line)
        else:
          assert N is not None

          levels = [map(int, line.split())]
          for j in xrange(N - 1):
            levels.append(map(int, next(fin).split()))

          value = calculate(levels)

          fout.write('Case #%d: ' % (i / 2,))
          fout.write(('%d\n' % value) if value is not None else 'Too Bad\n')

          N = levels = None
