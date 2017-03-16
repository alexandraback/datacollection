#f = open('ominous.txt', 'r')
f = open('D-large.in', 'r')
g = open('ominous.out', 'w')
lines = int(f.readline())
count = 1

while count <= lines:
  line = f.readline().split()
  omino = int(line[0])
  r = int(line[1])
  c = int(line[2])

  passed = False
  if r <= 0 or c <= 0:
    passed = False
  elif omino == 1:
    passed = True
  elif omino == 2:
    passed = (r*c) % 2 == 0
  elif omino == 3:
    passed = (r*c) % 3 == 0 and r >= 2 and c >= 2
  elif omino == 4:
    passed = (r*c) % 4 == 0 and r >= 3 and c >= 3
  elif omino == 5 and (r*c) % 5 == 0:
    passed = r >= 4 and c >= 4 or r == 3 and c >= 10 or r >= 10 and c == 3 
  elif omino == 6:
    passed = (r*c) % 6 == 0 and (r >= 6 and c >= 4 or r >= 4 and c >= 6)

  g.write('Case #' + str(count) + ': ' + ('GABRIEL' if passed else 'RICHARD') + '\n')
  count += 1
  
f.close()
g.close()
