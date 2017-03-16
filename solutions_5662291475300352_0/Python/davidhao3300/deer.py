f = open('C-small-1-attempt4.in')
o = open('output.txt', 'w')
n = int(f.readline())

for i in range(n):
  rows = int(f.readline().strip())
  hunters = []
  for j in range(rows):
    row = [int(x) for x in f.readline().strip().split(" ")]
    d = row[0]
    t_hunters = [[d, x] for x in row[2:]]
    hunters += t_hunters
  hunters = sorted(hunters)
  if len(hunters) == 1:
    o.write('Case #'+str(i+1)+': 0\n')
  else:
    if hunters[0][1] == hunters[1][1]:
      e = 0
    else:
      c_speed = 1.0/(1.0/hunters[0][1]-1.0/hunters[1][1])
      if c_speed < 0:
        c_speed *= -1
      #print c_speed
      if hunters[0][1] > hunters[1][1]:
        diff = hunters[0][0]-hunters[1][0]+360
        if 1.0*diff*c_speed < 1.0*(360-hunters[0][0])*hunters[0][1]:
          e = 1
        else:
          e = 0
      else:
        diff = hunters[1][0]-hunters[0][0]+360
        if 1.0*diff*c_speed < 1.0*(360-hunters[1][0])*hunters[1][1]:
          e = 1
        else:
          e = 0
    #print e
    o.write('Case #'+str(i+1)+': '+str(e)+'\n')
o.close()
f.close()