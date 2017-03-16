def solve(e, r, n, vs):
  d = {}
  for i in xrange(e + 1):
    d[i] = {}
    d[i][n] = 0
  for j in xrange(n-1, -1, -1):
    for i in xrange(e + 1):
      d[i][j] = max([k * vs[j] + d[min(i-k+r, e)][j+1] for k in xrange(i+1)])
  return d[e][0]

infile = open("input.txt", "r")
outfile = open("out.txt", "w")
lines = infile.read().split('\n')
cases = int(lines[0])

for i in xrange(1, cases + 1):
  [e, r, n] = map(int, lines[2*i - 1].split(' '))
  vs = map(int, lines[2*i].split(' '))
  outfile.write("Case #" + str(i) + ": " + str(solve(e, r, n, vs)) + '\n')

infile.close()
outfile.close()
