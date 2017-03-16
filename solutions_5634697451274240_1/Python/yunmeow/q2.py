def countF(line):
  p = "+"
  n = "-"
  #list_of_line = enumerate(line)
  first = line[0]
  counter = 0
  # count change 
  new_pos = 1
  current_type = first
  while new_pos != -1:
    if current_type == p:
      current_type = n
    else:
      current_type = p 
    new_pos = line.find(current_type, new_pos)
    if new_pos!= -1:
      counter = counter +1
  if counter%2==1:
    if first == "+":
      counter = counter+1
  if counter%2==0:
    if first == "-":
       counter = counter+1
  return counter

f = open("./B-small-attempt0.in", "r")
#f = open("./B-large.in", "r")
#f = open("test.in", "r")
inputList = list(f)
numTest = int(inputList[0])
counter = 1;
dictTable = {}
for line in inputList[1:]:
  need = countF(line)
  print ("Case #{}: {}".format(counter, need))
  counter+=1

