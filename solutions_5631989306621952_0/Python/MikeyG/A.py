def answer(n):
  word = n[0]
  for letter in n[1:]:
    if letter < word[0]:
      word += letter
    else:
      word = letter + word
  return word

with open("A-small.in") as f:
  with open("A-small.out", "w") as w:
    f.readline()
    question = 1
    for line in f:
      n = line.strip()
      output = answer(n)
    
      w.write("Case #{0}: {1}\n".format(question, output))
      question += 1
    

