import sys

def go (s):
  n = len(s)
  if n < 2:
    return s
  imx = n - 1
  for i in range (n-2, -1, -1):
    if s[imx] < s[i]:
      imx = i
  return s[imx] + go(s[:imx]) + s[imx+1:]

sys.setrecursionlimit(1500)
tests = input ()
for test in range (tests):
  s = raw_input()
  print ("Case #" + str(test + 1) + ": " + go(s))
         