def problemC(arguments):
  attack = {}
  wall = {}
  success = 0
  for line in arguments:
    for n in xrange(line[1]):
      attack.setdefault(line[0]+n*line[5], [])
      attack[line[0]+n*line[5]].append([line[2]+n*line[6], line[3]+n*line[6], line[4]+n*line[7]])
  print attack
  for day in xrange(max(attack.keys())+1):
    if day not in attack:
      continue
    build = {}
    for att in attack[day]:
      s = 0
      for ran in xrange(att[0], att[1]):
        wall.setdefault(ran, 0)
        if wall[ran] < att[2]:
          s = 1
          if ran not in build or build[ran] < att[2]:
            build[ran] = att[2]      
      success += s
      print wall, success
    for item in build:
      wall[item] = build[item]
  return success

f = open('c-small.in')
o = open('c-small.out', 'w')
n = int(f.readline())
for i in xrange(n):
  tribes = int(f.readline())
  arg = []
  for j in xrange(tribes):
    arg.append([int(c) for c in f.readline().split()])
  o.write('Case #%d: %d\n' % (i+1, problemC(arg)))
o.close()
f.close()
