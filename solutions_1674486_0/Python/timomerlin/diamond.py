input = open('input.in','r')
output = open('output.txt','w')
cases = int(input.readline())

def func(z):
  return int(z)-1

def path(c,s):
  current = s
  next = []
  passed = []

  while 1:
    
    passed.append(current)
    for i in range(len(c[current])):
      next.append(c[current][i])
    if len(next) != 0:
      current = next[0]
      next = next[1:]
    else:
      break
  return list(set(passed))
  
  
  
for x in range(cases):
  classes = []
  for y in range(int(input.readline().replace('\n',''))):
    classes.append(input.readline().replace('\n','').split(' ')[1:])
  classes = [map(func, t) for t in classes]
  splits = []
  for y in range(len(classes)):
    if len(classes[y]) > 1:
      splits.append(y)
  outword = 'No'
  for y in range(len(splits)):
    paths = []
    
    for z in range(len(classes[splits[y]])):
      paths.append(path(classes[:],classes[splits[y]][z]))
    l = paths[0]
    for z in range(len(paths)-1):
      for i in range(len(paths[z+1])):
        if paths[z+1][i] in l:
          outword = 'Yes'
          break
          break
          break
        else:
          l.append(paths[z+1][i])
  
  
  output.write('Case #' + str(x+1) + ': ' + outword + '\n')