input = open('input.in','r')
output = open('output.txt','w')
cases = int(input.readline())

def howmanylast(l):
  return l.count(min(l))


def finder(c):
  points = sum(c)
  lasts = []
  
  while points > 0:
    lasts = [i for i,n in enumerate(c) if n == min(c)]
    if points >= len(lasts):
      for z in range(len(lasts)):
        c[lasts[z]] += 1
      points -= len(lasts)
    else:
      for z in range(len(lasts)):
        c[lasts[z]] += points/len(lasts)
      break
  return c

for x in range(cases):
  contestants = input.readline().replace('\n','').split(' ')[1:]
  for y in range(len(contestants)):
    contestants[y] = float(contestants[y])
  outword = ''
  out = finder(contestants[:])
  p = sum(contestants)
  for y in range(len(contestants)):
    outword += str((out[y] - contestants[y])/p*100) + ' '
    
  outword.rstrip(' ')

  output.write('Case #' + str(x+1) + ': ' + outword + '\n')