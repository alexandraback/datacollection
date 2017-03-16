import string

inputFile = open('last_word.in', 'r')
inputData = inputFile.read().strip()

numCases  = int(inputData.split('\n')[0])
cases     = inputData.split('\n')

def formatAnswer(index, answer):
  return "Case #" + str(index) + ": " + str(answer)

def computeAnswer(word):
  lastWord = word[0]
  for letter in word[1:]:
    if letter >= lastWord[0]:
      lastWord = letter + lastWord
    else:
      lastWord = lastWord + letter
  return lastWord


for case in xrange(1,len(cases)):
  word = cases[case]

  answer = computeAnswer(word)
  print formatAnswer(case, answer)


