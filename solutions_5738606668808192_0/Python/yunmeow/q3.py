def findDivider(number, base):
  prime = [2, 3, 5, 7, 11, 13 ,17, 19, 23, 29, 31,37, 41,43,47, 53, 59,61, 67, 71, 73, 79, 83, 89, 97]
  real = 0
  for pos in number:
    real = real * base
    if pos == 1:
      real = real + 1
#  print (real)
  for test in prime:
    if real%test == 0:
      return test
  return 0

def increase2(old):
  new_num = old
  index = 14
  while new_num[index]:
    new_num[index] = 0
    index = index -1
  new_num[index]= 1
  return new_num

def findAll(first):
  result = []
  for base in range(2, 11):
    divider = findDivider(first, base)
    if divider == 0:
      return 0
    else:
      result.append(str(divider))
  first_str = [str(pos) for pos in first]
  print("{} {}".format("".join(first_str), " ".join(result)))
  return 1

N = 16 # lenth
J = 50 # number
first = [1,0,0,0,0,0,0,0,
         0,0,0,0,0,0,0,1]

print ("Case #1:")
for index in range(50):
  while not findAll(first): 
    first = increase2(first)
  first = increase2(first) 
