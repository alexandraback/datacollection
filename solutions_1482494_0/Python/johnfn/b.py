lines = [l[:-1] for l in open("in")][1:]

tt = 0
while len(lines) > 0:
  tt = tt + 1
  level_num = int(lines.pop(0))
  levels = []
  for x in range(level_num):
    levels.append([int(x) for x in lines.pop(0).split(" ")])

  beaten_levels = 0
  fail = False
  num_stars = 0
  leftovers = []

  while num_stars + len(leftovers) < level_num * 2:
    twostar = -1
    onestar = -1
    i = 0
    second = -1
    for l in levels:

      for q in range(len(leftovers)):
        if num_stars >= leftovers[q]:
          num_stars += 1
          leftovers[q] = -1
          beaten_levels += 1
      leftovers = [x for x in leftovers if x != -1]

      if len(l) > 1 and l[1] <= num_stars:
        twostar = i
        break

      if l[0] <= num_stars:
        if l[1] > second:
          second = l[1]
          onestar = i

      i += 1

    if twostar != -1:
      del levels[twostar]
      num_stars += 2
    elif onestar != -1:
      l = levels[onestar]
      leftovers.append(levels[onestar][1])
      del levels[onestar]
      num_stars += 1
    else:
      fail = True
      break

    leftovers = sorted(leftovers)

    beaten_levels += 1

  if fail:
    print "Case #%d: Too Bad" % (tt)
  else:
    print "Case #%d:" % (tt), beaten_levels + len(leftovers)
