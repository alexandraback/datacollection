cases = int(raw_input())
for case in range(1, cases+1):
  d = raw_input().split()
  a = int(d[0])
  b = int(d[1])
  o = raw_input().split()
  o = [float(x) for x in o]

  min_val = 1000000000000

  # case 1
  p = 1
  for x in o:
    p *= x
  min_val = min(min_val, p*(b-a+1) + (1-p)*(b-a+1+b+1))

  # case 3
  min_val = min(min_val, 2+b)

  # case 2
  for m in range(1, a+1):
    p = 1
    for q in range(0, a-m):
      p *= o[q]
    #print 'p', p
    #print 'v', p*(2*m+b-a+1) + (1-p)*(2*m+b-a+1+b+1)
    min_val = min(min_val, p*(2*m+b-a+1) + (1-p)*(2*m+b-a+1+b+1))




  print "Case #" + str(case) + ": " + str(min_val)
