inputFile = open('B-small-attempt0.in', 'r')

outputFile = open('output', 'w')


nbTests = int(inputFile.readline())

def incrI(index, m):
  i = len(index) - 1
  while i >= 0 and index[i] == m - 1:
    i -= 1

  index[i] += 1

  for j in range(i + 1, len(index)):
    index[j] = 0

  return index

def nbO(word,target):
  count = 0
  for i in range(len(word)-len(target) +1):
    if word[i:i+len(target)] == target:
      count += 1
  return count

for t in range(nbTests):
  k, l, s = inputFile.readline().split()
  k = int(k)
  l = int(l)
  s = int(s)
  keys = inputFile.readline()
  target = inputFile.readline()
  target = target[0:len(target)-1]
  
  maximum = 0.0
  average = 0.0

  word = []
  index = [0 for x in range(s)]

  for i in range(pow(k,s)):
    word = [keys[index[x]] for x in range(s)]
    word = ''.join(word)
    #print len(word)
    #print word
    #print target
    n = nbO(word,target)
    #print n
    average += n
    maximum = max(n, maximum)
    index = incrI(index,k)
    #if i % pow(k,s-1) == 0:
    #  print index

  average = average / pow(k,s)


  outputFile.write("Case #" + str(t + 1) + ": " + str(maximum - average) + "\n")
