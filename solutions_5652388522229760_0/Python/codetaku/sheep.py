import re


def digitSet(val):
  digits = set()
  while (val != 0):
    digits.add(val % 10)
    val /= 10
  return digits

readTests = False
numTests = 0
with open("C:/Users/codetaku/Documents/input.txt","r") as file1, open("C:/Users/codetaku/Documents/output.txt","w") as file2:
  testCase = 0
  for line in file1.readlines():
    if (not readTests):
      readTests = True
      numTests = int(line)
      continue
    testCase += 1
    if (testCase > numTests):
      break
    val = int(line)
    if (val == 0):
      ret = "Case #" + str(testCase) + ": INSOMNIA\n"
      file2.write(ret)
      print ret
      continue
    digits = set()
    mult = 1
    while (len(digits) < 10):
      digits.update(digitSet(val * mult))
      mult += 1
    ret = "Case #" + str(testCase) + ": " + str(val * (mult-1)) + "\n"
    file2.write(ret)
    print ret
  
