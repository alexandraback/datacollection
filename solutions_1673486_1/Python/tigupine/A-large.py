infile = open("A-large.in", "r")
outfile = open("A-large.out", "w")

data = [l.strip() for l in infile.readlines()]

numcases = int(data.pop(0))
     
for case in range(numcases):
  print "Case " + str(case+1)
  ab = data.pop(0).split(' ')
  a = int(ab[0])
  b = int(ab[1])
  probs = [float(p) for p in data.pop(0).split(' ')]
  best = 1 + b + 1
  probcorrectsofar = 1
  for i in range(len(probs)):
    probcorrectsofar *= probs[i]
    backspacesneeded = a-(i+1)
    keystrokesforoption2ifwrong = 2*backspacesneeded + (b-a) + 1 + b + 1
    keystrokesforoption2ifright = 2*backspacesneeded + (b-a) + 1
    option2ex = probcorrectsofar*keystrokesforoption2ifright + (1.0-probcorrectsofar)*keystrokesforoption2ifwrong
    if option2ex < best:
      best = option2ex
  outfile.write("Case #" + str(case+1) + ": " + str(best) + "\n")
