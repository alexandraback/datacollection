import sys

vowels = "aeiou"

def nval(name, n):
  val = 0
  last = 0
  i = 0
  while i < len(name)-n+1:
    s = name[i:i+n]
    if len(s) < n:
      break
    good = True
    for c in s:
      if c in vowels:
        good = False
        break
    if good:
      before = i-last+1
      after = len(name)-(i+n)+1
      val += before * after
      last = i+1
    i += 1
  return val


if __name__=="__main__":
  lines = sys.stdin.readlines()

  for i in range(1, len(lines)):
    line = lines[i].strip().split(' ')
    name = line[0]
    n = int(line[1])
    res = nval(name, n)
    print "Case #{}: {}".format(i, res)
