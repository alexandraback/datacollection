#!/usr/bin/python
import numpy as np

def findLevel(levels, stars, completed):
  i = len(levels) -1
  
  while i >=0 :
    if levels[i][1] <= stars and levels[i][0] not in completed:
      return levels[i][0]
    i = i - 1

  return -1

def findLevel2(levels, stars, completed):
  i = len(levels) -1
  
  while i >=0 :
    if levels[i][2] <= stars and levels[i][0] not in completed:
      return levels[i][0]
    i = i - 1

  return -1

f = open("B-small")
num = int(f.readline())

for i in range(0, num):
  num_levels = int(f.readline().rstrip())
 
  star = []
  current_stars = 0
  completed = []
  one_completed = []
  for j in range(0, num_levels):
    line = f.readline().rstrip()
    words = line.split(None)
    star.append([j+1, int(words[0]), int(words[1])])
  
  two = np.array(star)
  two.view('i8,i8,i8').sort(order=['f2'], axis=0)

  moves = 0
  while(len(completed) != num_levels):
    level = findLevel2(two, current_stars, completed)
    if (level != -1):  
      if level in one_completed:
        current_stars += 1
      else:    
        current_stars += 2
      completed.append(level)
    else:
      level = findLevel(two, current_stars, completed)
      if level == -1:
        #Cannot be completed
        moves = "Too Bad"
        break
      else:
        one_completed.append(level)
        current_stars += 1
    moves += 1

  output = 'Case #' + str(i+1) + ': ' + str(moves)
  print output

  

