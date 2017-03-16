in_file = "C-small-attempt0.in"
counter = 0
N = 0
for line in open(in_file, 'r'):
  if counter == 0:
    counter += 1
    continue
  kids = line.strip('\n').split(" ")
  if len(kids) == 1:
    N = int(kids[0])
  else:
    bffs = dict()
    bffs_inv = dict()
    for ind in range(len(kids)):
      bffs[ind+1] = int(kids[ind])
    max_cycle = 0
    for start in range(1, N+1):
      current_kid = start
      already_seated = list()
      while (current_kid not in already_seated):
        already_seated.append(current_kid)
        current_kid = bffs[current_kid]
      if bffs[already_seated[-1]] == already_seated[0]:
        max_cycle = max(max_cycle, len(already_seated))
      elif bffs[already_seated[-1]] == already_seated[-2]:
        one_more = False
        for k in bffs:
          one_more = one_more or ( (bffs[k] == already_seated[-1]) and (k not in already_seated) )
          if one_more:
            max_cycle = max(max_cycle, len(already_seated) + 1)
          else:
            max_cycle = max(max_cycle, len(already_seated))
      else:
        max_cycle = max(max_cycle, len(already_seated) - 1)
    answer_string = 'Case #' + str(counter) + ': ' + str(max_cycle)
    counter += 1
    print(answer_string)
