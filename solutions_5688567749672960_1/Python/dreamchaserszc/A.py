import fileinput

class TestCase(object):
  def __init__(self, num):
    self.num = num

def solve(t):

  if t.num < 21:
    return t.num

  count = 1
  
  while (t.num != 1):
    if (str(t.num).endswith('0')):
      t.num = t.num - 1
      count = count + 1
      
      #print "t.num " + str(t.num) + " count " + str(count)
      continue

    length = len(str(t.num))
    if (length > 1):
      digits = str(t.num)[length/2:]
      if not (int(digits) == 1):
        diff = int(digits) - 1
        count = count + diff
        t.num = t.num - diff
    #print "the digits split is " + digits
    #while (length > 1) and not (int(digits) == 1):
      #t.num = t.num - 1
      #count = count + 1
      #length = len(str(t.num))
      #digits = str(t.num)[length/2:]
      #print "t.num " + str(t.num) + " count " + str(count)
    
    #print t.num
    if int(str(t.num)[::-1]) < t.num:
      count = count + 1
      t.num = int(str(t.num)[::-1])
      #print "t.num " + str(t.num) + " count " + str(count)
      continue
    t.num = t.num - 1
    count = count + 1
    #print "t.num " + str(t.num) + " count " + str(count)

  return count

start = True
i = 0
numberOfT = 0
testCases = []

for line in fileinput.input():
  if start:
    numberOfT = int(line)
    start = False
    continue
    
  data = [x for x in line.split()]
  t = TestCase(int(data[0]))
  testCases.append(t)

i = 1
f = open('answer', 'w')
for t in testCases:
  answer = solve(t)
  f.write("Case #" + str(i) + ": " + str(answer) + "\n")
  i = i + 1


