def is_con(c):
  return c not in ['a', 'e', 'i', 'o', 'u']

infile = open("input.txt", "r")
outfile = open("out.txt", "w")
lines = infile.read().split('\n')
cases = int(lines[0])

for i in xrange(1, cases + 1):
  [word, n] = lines[i].split(' ')
  n = int(n)
  con = [0] * len(word)
  con[0] = 1 if is_con(word[0]) else 0
  total = 0
  m = 0

  for j in xrange(1, len(word)):
    if is_con(word[j]):
      con[j] = con[j-1] + 1
    else:
      con[j] = 0
    if con[j] >= n:
      total += j - n + 2
      m = j - n + 2
    else:
      total += m
  
  outfile.write("Case #" + str(i) + ": " + str(total) + "\n")

infile.close()
outfile.close()
