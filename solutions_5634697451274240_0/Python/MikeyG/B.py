def answer(n):
  flips = 0
  last_char = -1
  for char in n:
    if last_char == -1:
      last_char = char
      continue
    if last_char != char:
      last_char = char
      flips += 1
      continue
    
  if n[-1] == "-":
    flips += 1
   
  return flips

with open("B.in") as f:
  with open("B-small.out", "w") as w:
    f.readline()
    question = 1
    for line in f:
      n = line.strip()
      output = answer(n)
    
      w.write("Case #{0}: {1}\n".format(question, output))
      question += 1
    

