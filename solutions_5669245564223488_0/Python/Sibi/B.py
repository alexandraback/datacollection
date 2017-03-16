import sys, itertools, multiprocessing

iFile = open(sys.argv[1],"r")

size = int(iFile.readline().strip())

def dostuff(perm):
  train = "".join(perm)
  
  seen = [False]*26
  last = -1
  
  for char in train:
    value = ord(char)-ord('a')
    if last == -1:
      last = value
      seen[value] = True
      
    if value != last and seen[value]:
      return 0
    else:
      last = value
      seen[value] = True
      
  return 1

p = multiprocessing.Pool(8)


for i in range(size):

  line = iFile.readline().strip()
  
  N = int(line)

  old_cars = iFile.readline().strip().split()
  
  score = 0
  
  cars = []
  
  for car in old_cars:
    last_char = ""
    new_car = ""
    for char in car:
      if char != last_char:
        new_car = new_car+char
        last_char = char
    cars.append(new_car)
      
      
  temp = p.map(dostuff,itertools.permutations(cars))   
  
  score = sum(temp)
  
  output = str(score)
  
  print("Case #"+str(i+1)+": "+output)
