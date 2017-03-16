from sys import stdin

def isVowel(c):
   if c == 'a' or c == 'e' or c == 'i' or c == 'o' or c == 'u':
      return '0'
   else:
      return '1'

def convert(s):
   return ''.join(map(isVowel, s))

def solve(s, n):
   count = 0
   # print "----"
   # print s

   for i in range(n, len(s)+1):
      ss = s[0:i]
      # print ss
      if '1'*n in ss:
         count += 1

   if len(s) > 0:
      count += solve(s[1:], n)
   return count

T = int(stdin.readline())
for t in range(T):
   s, n = stdin.readline().split()
   print "Case #{}: {}".format(t+1, solve(convert(s), int(n)))
