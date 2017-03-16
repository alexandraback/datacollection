import re




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
    arr = line.split(" ")
    k = int(arr[0])
    c = int(arr[1])
    s = int(arr[2])
    if (s == k):
      ret = "Case #" + str(testCase) + ":"
      val = 1
      while (val <= s):
        ret += " " + str(val)
        val += 1
      ret += "\n"
      file2.write(ret)
      print ret
      continue
    if (s * c < k):
      ret = "Case #" + str(testCase) + ": IMPOSSIBLE\n"
      file2.write(ret)
      print ret
      continue
    #now we try for real
    vals = ""
    placed = 0
    #you can always get C pieces of information per run, so do it sequentially
    while (placed < k):
      pos = 1
      tmp = 1
      while (tmp <= c and tmp + placed - 1 < k):
        pos += k ** (c - tmp) * (placed + tmp - 1)
        tmp += 1
      vals += " " + str(pos)
      placed += c
    ret = "Case #" + str(testCase) + ":" + vals + "\n"
    file2.write(ret)
    print ret
