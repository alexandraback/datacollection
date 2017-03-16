def answer(K, C, S):
  if C * S < K:
    return "IMPOSSIBLE"
    
  students_needed = (K-1)/C + 1
  
  positions = []
  index = 0
  for s in range(students_needed):
    next_painter = 0
    for j in range(C):
      if index >= K:
        continue
      next_painter += index * K**(C-j-1)
      index += 1
    positions.append(next_painter + 1)
    
  return " ".join([str(p) for p in positions])
        


with open("D-large.in") as f:
  with open("D-large.out", "w") as w:
    f.readline()
    question = 1
    for line in f:
      n = [int(d) for d in line.strip().split()]
      output = answer(n[0], n[1], n[2])
    
      print output
      w.write("Case #{0}: {1}\n".format(question, output))
      question += 1
    

