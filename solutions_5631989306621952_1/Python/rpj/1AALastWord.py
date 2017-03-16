import itertools
input = 'CAB'

def lstWord(input):
    lst = [input[0]]
    lst2 = []
    for letter in input[1:]:
      for word in lst:
          lst2.append(max('%s%s' % (word, letter), '%s%s' % (letter, word)))
      lst[:] = lst2
      lst2 = []
    return max(lst)

inputNb = None
case = 'large'
outputFile = open(r'C:\Users\Remi\Code\Data\1A\A-%s.out' % case, 'w')
for i, line in enumerate(open(r'C:\Users\Remi\Code\Data\1A\A-%s.in' % case)):
    if not inputNb:
        inputNb = int(line)
        continue
    outputFile.write('Case #%s: %s' % (i, lstWord(line)))
outputFile.close()