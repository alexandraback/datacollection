infile = open("B-large.in", "r")
outfile = open("B-large.out", "w")

data = [l.strip() for l in infile.readlines()]

numcases = int(data.pop(0))

for case in range(numcases):
  print "Case " + str(case+1)
  numlevels = int(data.pop(0))
  leveldata = []
  for level in range(numlevels):
    thislevel = [int(n) for n in data.pop(0).split(' ')]
    thislevel = [thislevel[1], thislevel[0]]
    leveldata.append(thislevel)
  leveldata = sorted(leveldata)
  leveldata = [[i[1], i[0]] for i in leveldata]
  gamesplayed = 0
  gamestars = [0]*numlevels
  totalstars = 0
  answer = ""

  while totalstars < numlevels*2:
 
    twostaropportunities = True
    onestaropportunities = True
    didsomethingcycle = False
    didsomethingtwo = False

    while twostaropportunities and len(leveldata) > 0:       
      x = 0
      while x < len(leveldata):
        if totalstars >= leveldata[x][1]:
          starsearned = 2
          if leveldata[x][0] == 2002:
            starsearned = 1
          gamesplayed += 1
          totalstars += starsearned
          leveldata.pop(x)
          didsomethingtwo = True
          break
        else:
          x += 1
      twostaropportunities = False

    while onestaropportunities and not didsomethingtwo and not didsomethingcycle and len(leveldata) > 0:       
      x = len(leveldata)-1
      while x >= 0:
        if totalstars >= leveldata[x][0]:
          gamesplayed += 1
          totalstars += 1
          leveldata[x][0] = 2002
          didsomethingcycle = True
          break
        else:
          x -= 1
      onestaropportunities = False

    if not didsomethingtwo and not didsomethingcycle:
      answer = "Too Bad"
      break 
  
  if answer != "Too Bad":
    answer = str(gamesplayed)

  outfile.write("Case #" + str(case+1) + ": " + answer + "\n")
