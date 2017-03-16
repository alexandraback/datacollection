import sys

def prefer(lhs, rhs):
  if (len(lhs) == len(rhs)):
    if (len(lhs) == 1):
      return True
    else:
      return lhs[1] > rhs[1]
  else:
    return len(lhs) < len(rhs)

filename = sys.argv[1]

infile = open(filename)

T = int(infile.readline())

for x in range(T):
  sys.stdout.write("Case #")
  sys.stdout.write(str(x+1))
  sys.stdout.write(": ")
  
  N = int(infile.readline())
  levelscores = []
  for i in range(N):
    levelscores.append([int(v) for v in infile.readline().split()])
    
  curr_score = 0
  games = 1
  keep_going = True
  
  while (keep_going):
    picked_index = -1
    picked_subindex = -1
    curr_index = 0
    
    for levelscore in (levelscores):
      if (len(levelscore) == 2 and levelscore[1] <= curr_score):
        picked_index = curr_index
        picked_subindex = 1
        break
      elif (len(levelscore) >= 1 and levelscore[0] <= curr_score):
        if (picked_index == -1 or prefer(levelscore, levelscores[picked_index])):
          picked_index = curr_index
          picked_subindex = 0
      curr_index = curr_index + 1
    
    if (picked_index != -1):
      curr_score = curr_score + 1 + picked_subindex
      
      levelscores[picked_index] = levelscores[picked_index][picked_subindex+1:]
      if (not len(levelscores[picked_index])):
        levelscores.pop(picked_index)
    else:
      keep_going = False
      
    if (len(levelscores)):
      games = games + 1
  
  if (len(levelscores)):
    print "Too Bad"
  else:
    print games   
  
  
infile.close()