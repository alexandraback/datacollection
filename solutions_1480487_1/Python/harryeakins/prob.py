#! /usr/bin/python
N = int(raw_input())

for i in range(N):
  inStr = raw_input().split()
  n = int(inStr[0])
  points = map(lambda x: float(x), inStr[1:])
      
  e_points = enumerate(points)
  s_points = sorted(e_points, key=lambda x: x[1])
  X = sum(points)

  num_sticks_eq = 1
  current_level = s_points[0][1] + X
  try:
    #print "CL:", current_level
    while s_points[num_sticks_eq][1] < current_level:
      new_point = s_points[num_sticks_eq][1]
      difference = current_level - new_point
      #print "DIFF:", difference
      #print "NSE:", num_sticks_eq
      current_level -= difference - (difference*num_sticks_eq/(num_sticks_eq+1))
      #print "CL:", current_level
      num_sticks_eq += 1
  except IndexError:
    pass
  #print "NSE:", num_sticks_eq

  print "Case #%d:" % (i+1),
  for j in range(n):
    if points[j] > current_level:
      print 0.0, 
    else:
      print 100*(current_level-points[j])/X,
  print
    
     
