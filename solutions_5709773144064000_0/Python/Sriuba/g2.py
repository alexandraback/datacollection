# input
fi = open("python/input.txt", "r")
fo = open("python/output.txt", "wb")
t = int(fi.readline())

for i in range(0, t):
  line = [float(x)for x in fi.readline().split(' ')]
  C = line[0]
  F = line[1]
  X = line[2]
  n = int(X/C - 2.0/F) #number of farms required
  if n > 0:
    output = 0.0
    for j in range(0, n):
      output = output + C/(2 + F*j)
    output = output + X/(2 + F*n)
  else:
    output = X/2
  fo.write(bytes("Case #"+str(i+1)+": "+"{0:.7f}".format(output)+'\n', 'UTF-8'))
fi.close()
fo.close()
