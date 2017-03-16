infile = open("input.txt", "r")
outfile = open("out.txt", "w")
lines = infile.read().split('\n')
cases = int(lines[0])

for i in xrange(1, cases + 1):
  [x, y] = map(int, lines[i].split(' '))
  d_old = {(0, 0) : ""}
  d_new = {}
  l = 1

  found = False
  while not found:
    for (a, b) in d_old.keys():
      if (a, b) == (x, y):
        found = True
        outfile.write("Case #" + str(i) + ": " +  d_old[(a, b)] + "\n")
      d_new[(a+l, b)] = d_old[(a, b)] + "E"
      d_new[(a-l, b)] = d_old[(a, b)] + "W"
      d_new[(a, b+l)] = d_old[(a, b)] + "N"
      d_new[(a, b-l)] = d_old[(a, b)] + "S"
    d_old = d_new
    d_new = {}
    l += 1

infile.close()
outfile.close()
