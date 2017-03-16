import sys

def f(C,F,X,times):
   if X <= C:
      return X / 2.0

   cookies_per_sec = 2.0
   time = 0.0
   for i in range(1,times):
      delta_c = C / cookies_per_sec
      time = time + delta_c

      cookies_per_sec = cookies_per_sec + F

   time = time + (X / cookies_per_sec)

   return time

NC = int(input(''))
for i in range(1,NC+1):
   C,F,X = input('').split()

   C = float(C)
   F = float(F)
   X = float(X)

   ans = f(C,F,X,1)
   best = 1
   for j in range(2,5000000):
      tmp = f(C,F,X,j)
      if tmp < ans:
         ans = tmp
         best = j
      elif tmp > ans:
         break

   print('Case #%d: %.7f' % (i,ans))