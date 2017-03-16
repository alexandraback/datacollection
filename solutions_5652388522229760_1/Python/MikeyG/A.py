def answer(n):
  if n == 0:
    return "INSOMNIA"
  seen = [0]*10
  
  last_num = n
  while True:
    current_num = last_num
  
    while current_num != 0:
        last_digit = current_num % 10
        seen[last_digit] = 1
        current_num = current_num / 10
      
    if sum(seen) == 10:
      return last_num
      
    last_num = last_num + n

with open("A-large.in") as f:
  with open("A-large.out", "w") as w:
    f.readline()
    question = 1
    for line in f:
      n = int(line.strip())
      output = answer(n)
    
      w.write("Case #{0}: {1}\n".format(question, output))
      question += 1
    

