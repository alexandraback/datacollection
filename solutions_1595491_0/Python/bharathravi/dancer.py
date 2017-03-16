#!/usr/bin/python

"""
Note this is assuming scores are all valid, of course
"""
def ispossible(points, best):
  if points < best + max(best - 2, 0) * 2:
    # Never possible for this score to have a best score >= "best"
    # because this is the lowest possible score needed for that.
    return -1

  # Now check if it's possible to get this score
  # without a surprise, with the best score being >= "best"
  for i in range(best, 11):
    if points >= i + max(i - 1, 0)*2 and \
       points <= i + min(i + 1, 10)*2:
      # This is the range where a score of "i" or higher 
      # can be achieved without a surprise
      return 0

  
  # Else you need a surprise to get an abnormally high score
  return 1


def find(points, surprises, best):
  num = len(points)
  count = 0
  s = surprises
  for i in range(0, num):
    x = ispossible(int(points[i]), best)
    if x == 0:
      count += 1
#      print "Safe", points[i]
    elif x == 1:
      if s > 0:
        # "Use up" a surprise
        s -= 1
        count += 1
#        print "Not Safe", points[i]
#      else:
#        print "Impossibru", points[i]
#    else:
#      print "Impossibru", points[i]

  return count

#print find([8, 0], 1, 1)

f = open('input3')
num = int(f.readline())

for i in range(0, num):
  output = 'Case #' + str(i+1) + ': '
  line = f.readline().rstrip()
  words = line.split(None)
  surprises = int(words[1])
  best = int(words[2])
  points = words[3:]

  output += str(find(points, surprises, best))
  print output

