#!/usr/bin/python


f = open('B-large.in')
#f = open('B-sample.in')
inputline = f.readline()
numcase = int(inputline)

fout = open('b_result_large.txt', 'w')
levels = []
done = []
poss_move = []
numlevel = 0
extra = 0 
move_made = []
def next_move(totstars):
  global extra
  global poss_move
  global move_made
  extra = 0
  for i in range(0, numlevel):
    if done[i][1] == 0 and levels[i][1] <= totstars:
      done[i][1] = 1
      extra = 2 - done[i][0]
      done[i][0] = 1
      move_made.append([i,1])
      #print " **Twostars** at:",i
      return 2
    elif done[i][0] == 0 and levels[i][0] <= totstars:
      poss_move.insert(0,i)
  if len(poss_move) == 0:
    return 0
  else:
    return 1

def make_move():
  global poss_move
  global levels
  current_level = poss_move[0]
  next_level_req = levels[current_level][1]
  #print poss_move
  for i in range (1, len(poss_move)):
    #print "   ###i=",i," next=",next_level_req," poss_now=",poss_move[i]
    if levels[poss_move[i]][1] > next_level_req:
      next_level_req = levels[poss_move[i]][1]
      current_level = poss_move[i]
  move_made.append([current_level,0])
  #print "  **A Star** at:",current_level, " out of possible=",len(poss_move)
  done[current_level][0] = 1


for i in range (0,numcase):
  line = f.readline()
  numlevel = int(line)
  levels = []
  done = []
  for j in range (0,numlevel):
    line = f.readline()
    linelist = line.split()
    level1 = int(linelist[0])
    level2 = int(linelist[1])
    stars_req = [level1,level2]
    levels.append(stars_req)
    init_done = [0,0]
    done.append(init_done)
  #print levels 
  totgames = 0
  totstars = 0
  reqstars = numlevel * 2
  move_made = []
  while totstars < reqstars:
    poss_move = []
    #print "Total=",totstars
    stars = next_move(totstars)
    if (stars == 0):
      break
    else:
      if stars == 2:
	#print " adding two stars extra=",extra
	totstars = totstars + extra
	totgames = totgames + 1
      else:
	#print " make_move"
	make_move()
	totstars = totstars + 1
	totgames = totgames + 1

  #print "totstars=",totstars," req=",reqstars
  if totstars < reqstars:
    answer = "Too Bad"
  else:
    answer = str(totgames)
  #print move_made
  answ_sentence = "Case #"+str(i+1)+": "+ answer
  fout.write(answ_sentence)
  fout.write('\n')
  #print "Case #"+str(i+1)+": "+ answer
  #print "\n"


f.close()
fout.close()


