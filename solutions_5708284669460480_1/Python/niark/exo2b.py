from math import floor

inputFile = open('B-large.in', 'r')

outputFile = open('output', 'w')

alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"

nbTests = int(inputFile.readline())

def nbO(word,target):
  count = 0
  for i in range(len(word)-len(target) +1):
    if word[i:i+len(target)] == target:
      count += 1
  return count

def ctoint(c):
  index = -1
  for i in range(26):
    if alphabet[i] == c:
      index = i
  return index

def nbC(k,c):
  count = 0
  for i in range(len(k)):
    if k[i] == c:
      count += 1
  return count



for t in range(nbTests):
  k, l, s = inputFile.readline().split()
  k = int(k) # len(keys)
  l = int(l) # len(target)
  s = int(s) 
  keys = inputFile.readline()
  target = inputFile.readline()
  target = target[0:len(target)-1]
  
  maximum = 0.0
  average = 1.0

  ctoint("Z")
  repartition = [nbC(keys, alphabet[i]) for i in range(len(alphabet))]
  print repartition

  for i in range(l):
    average *= repartition[ctoint(target[i])]

  average = (s - l + 1) * average / pow(k,l)

  if average == 0:
    outputFile.write("Case #" + str(t + 1) + ": 0\n")
  else:
    k = 1
    while k < l and target[k:l] != target[0:l-k]:
      #print target[k:l] + " coucou " + target[0:l-k]
      k += 1
    #print k

    maximum = floor((s - l) / k) + 1
    outputFile.write("Case #" + str(t + 1) + ": " + str(maximum - average) + "\n")




  #average = average / pow(k,s)


