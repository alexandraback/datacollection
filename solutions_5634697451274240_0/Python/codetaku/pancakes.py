def recursiveFlip(pancakes):
  if (len(pancakes) == 0):
    return 0
  flips = 0
  check = len(pancakes) - 1
  end = pancakes[check]
  if (end == "-"):
    flips += 1
    check -= 1
    while (check >= 0 and pancakes[check] != "+"):
      check -= 1
    if check >= 0: #we know we're currently on a plus
      flips += 1
  while (check >= 0 and pancakes[check] != "-"):
    check -= 1
  if (check >= 0):
    flips += recursiveFlip(pancakes[0:check+1])
  return flips

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
    flips = recursiveFlip(line)
    ret = "Case #" + str(testCase) + ": " + str(flips) + "\n"
    file2.write(ret)
    print ret
