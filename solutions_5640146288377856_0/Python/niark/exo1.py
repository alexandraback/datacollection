from math import ceil

inputFile = open('A-small-attempt2.in', 'r')
#inputFile = open('input', 'r')

outputFile = open('output', 'w')


nbTests = int(inputFile.readline())

for i in range(nbTests):
  r, c, w = inputFile.readline().split()
  r = float(r)
  c = float(c)
  w = float (w)

  outputFile.write("Case #" + str(i + 1) + ": " + str(int(ceil(r*c/w - 1) + w)) + "\n")
