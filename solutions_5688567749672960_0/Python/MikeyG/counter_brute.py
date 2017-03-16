with open("A.in") as f:

  dict = {1:1}
  
  queue = [1]
  
  
  while len(queue) != 0:
    q = queue[0]
    queue = queue[1:]
    
    if q+1 < 1000002:
      if q+1 in dict:
        if dict[q+1] > dict[q] + 1:
          dict[q+1] = dict[q] + 1
          queue.append(q+1)
      else:
        dict[q+1] = dict[q]+1
        queue.append(q+1)
        
    rev = int(str(q)[::-1])
    if rev < 1000002:
      if rev in dict:
        if dict[rev] > dict[q] + 1:
          dict[rev] = dict[q] + 1
          queue.append(rev)
      else:
        dict[rev] = dict[q] + 1
        queue.append(rev)
      
    

  num_cases = int(f.readline().strip())
  for case in range(1,num_cases+1):
    start_number = int(f.readline().strip())
    
    print("Case #{}: {}".format(case, dict[start_number]))