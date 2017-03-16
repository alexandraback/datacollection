with open("B-large.in") as f:
  with open("B-large.out", "w") as w:
    f.readline()
    question = 1
    num_rows = int(f.readline().strip())
    
    while num_rows != "":
      counts = {}
      for i in range(2*num_rows-1):
        line = f.readline().strip().split()
        for l in line:
          if l in counts:
            counts[l] += 1
          else:
            counts[l] = 1
      print counts
      
      odd_counts = []
      for c in counts.items():
        if int(c[1]) % 2 == 1:
          odd_counts.append(int(c[0]))
          
      print odd_counts
      answer = " ".join([str(s) for s in sorted(odd_counts)])
      
      w.write("Case #{0}: {1}\n".format(question, answer))
      question += 1
      try:
        num_rows = int(f.readline().strip())
      except:
        num_rows = ""
    

