import sys

def check(seq,char):
  usedT = False
  for c in seq:
    if c == 'T':
      if usedT == True:
        return False
      usedT = True
    elif c != char:
      return False
  return True

def evalseq(seq,i):
  if check(seq,'X'):
    print "Case #" + str(i+1) + ": " + "X won"
    return True
  if check(seq,'O'):
    print "Case #" + str(i+1) + ": " + "O won"
    return True
  return False

with open(sys.argv[1],"r") as f:
  T = int(f.next())
  for i in xrange(T):
    done = False
    game = []
    for k in xrange(4):
      rowstr = f.next()
      row = [rowstr[l] for l in xrange(4)]
      game.append(row)
    f.next()

    for row in game:
      if evalseq(row,i):
        done = True
        break
    if done:
      continue

    for j in range(4):
      if evalseq([row[j] for row in game],i):
        done = True
        break
    if done:
      continue

    if evalseq([row[j] for j,row in enumerate(game)],i):
      continue
    if evalseq([row[3-j] for j,row in enumerate(game)],i):
      continue

    for row in game:
      if '.' in row:
        print "Case #" + str(i+1) + ": " + "Game has not completed"
        done = True
        break
    if done:
      continue

    print "Case #" + str(i+1) + ": " + "Draw"
