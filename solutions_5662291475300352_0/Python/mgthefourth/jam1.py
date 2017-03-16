#for a maximum of two hikers our ouput is 0 or 1


for tc in range(int(input())):
  hikers = []
  for group in range(int(input())):
    line = [int(x) for x in input().split()]
    pos = line[0]
    num = line[1]
    time = line[2]
    for i in range(num):
      hikers.append((pos, time+i))
  hikers = sorted(hikers, key=lambda x: (x[1], -x[0]))
  #at t = 0
  t = 0
  a = hikers[0][0]
  b = hikers[1][0]
  u = 360/hikers[0][1]
  v = 360/hikers[1][1]

  #case where a reaches origin first
  if (((360-a)/u)<((360-b)/v)):
    #when the faster hiker (a) reaches the origin
    t = (360-a)/u
    b = v*t+b
    b = b%360
    a = 0

    #hypothetically work out how long it would take b to get to the orgin
    i = (360-(b))/v

    #work out when a will overtake b
    if (u!=v):
      j = b/(u-v)
    else:
      j = float("inf")

    #work out which occurs first
    if (i>=j):
      out = 1
    else:
      out = 0
  #case where b reaches the orgin first
  else:
    out = 0

  print ("Case #%d: %d" % (tc+1, out))
