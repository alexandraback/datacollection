import math

def is_palindrome(x):
  s = str(x)
  n = len(s)
  for i in range(n):
    if s[i] != s[n - i - 1]:
      return False
  return True

def count(a, b):
  res = 0
  for x in range(a, b + 1):
    sq = int(math.sqrt(x))
    if sq * sq == x and is_palindrome(x) and is_palindrome(sq):
      res = res + 1
  return res

def get_ints(line):
  line = line.split(" ")
  return [int(item) for item in line]

with open("c.in", "rb") as file:
  tn = int(file.readline())
  for test in range(tn):
    tmp = get_ints(file.readline())
    a = tmp[0]
    b = tmp[1]

    result = count(a, b)
    print "Case #{test}: {result}".format(test = test + 1, result = result)
