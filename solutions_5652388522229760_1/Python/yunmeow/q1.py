def count(initial):
 
  set_list = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
  work_number = initial
  save_number = 0
  while set_list:
    work_number = save_number + initial
    save_number = work_number
    while work_number:
      digit = work_number%10
      if digit in set_list:
        set_list.remove(digit)
      work_number = int(work_number/10)
  final = save_number 
      
  return final


#f = open("./A-large.in", "r")
f = open("./A-small-attempt0.in", "r")
#f = open("./test.in", "r")
inputList = list(f)
numTest = int(inputList[0])
#print (numTest)
counter = 1
numLabel = -1
for line in inputList[1:]:
  init = int(line)
  if init == 0:
    print ("Case #{}: INSOMNIA".format(counter))
  else :
    final = count(init) 
    print ("Case #{}: {}".format(counter, final))
  counter+=1

