infile = open("input.txt", "r")
outfile = open("out.txt", "w")
lines = infile.read().split('\n')
cases = int(lines[0])

for i in xrange(1, cases + 1):
  [r, t] = lines[i].split(' ')
  r = int(r)
  t = int(t)
  outfile.write("Case #" + str(i) + ": " + str(int(((1 - 2*r) + ((2*r - 1)**2 + 8*t)**0.5)/4.0)) + '\n')

infile.close()
outfile.close()
