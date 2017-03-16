import random

with open("C-small.out", "w") as w:
  w.write("Case #1:\n")
  used = set([])
  for iter in range(50):
  
    while True:
      code = [0]*16
      code[0] = 1
      code[-1] = 1
    
      i = random.randint(1,7)
      j = i
      while j == i:
        j = random.randint(1,7)
      code[i*2] = 1
      code[j*2] = 1
      
      i = random.randint(0,6)
      j = i
      while j == i:
        j = random.randint(0,6)
      code[i*2+1] = 1
      code[j*2+1] = 1
      
      jamcoin = "".join([str(c) for c in code])
      
      if jamcoin not in used:
        used.add(jamcoin)
        break
    
    print iter, jamcoin
    w.write("{0} 3 2 3 2 7 2 3 2 3\n".format(jamcoin))