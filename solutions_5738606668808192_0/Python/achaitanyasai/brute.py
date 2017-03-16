import random
import sys

def check(a, s, d, n):
   x = pow(a, d, n)
   if(x == 1):
      return True
   s -= 1
   for i in xrange(s):
      if(x == n - 1):
         return True
      x = pow(x, 2, n)
   if(x == n - 1):
      return True
   return False

def millerrabin(n, runs):
   if(n == 2):
      return True
   if(n % 2 == 0):
      return False
   s = 0
   d = n - 1
   while(d % 2 == 0):
      d /= 2
      s += 1
   for i in xrange(runs):
      a = random.randrange(2, n - 1)
      if(not check(a, s, d, n)):
         return False
   return True

def get(n):
   i = 2
   while(i * i <= n):
      if(n % i != 0):
         i += 1
      else:
         return i

T = input()
for test in xrange(1, T + 1):
   a = set()
   L, R = map(int, raw_input().split(' '))
   while(len(a) != R):
      S = ''
      while(len(S) != L):
         if(len(S) == 0):
            S += '1'
         elif(len(S) == L - 1):
            S += '1'
         else:
            S += str(random.randint(0, 1))
      flag = True
      for i in xrange(2, 11):
         if(millerrabin(int(S, i), 50) == True):
            flag = False
      if(flag):
         a.add(S)
   print "Case #" + str(test) + ':'
   for i in a:
      print i, 
      for j in xrange(2, 11):
         print get(int(i, j)), 
      print
      sys.stdout.flush()